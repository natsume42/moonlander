#include "heatmap.h"
#include "rgb_matrix_utils.h"
#include "math.h"

static uint16_t   keycount[DRIVER_LED_TOTAL];
static bool       disabled_keys[DRIVER_LED_TOTAL];
static uint16_t   max, min;
static bool       heatmap_enabled = false;
static const char separator[]     = " ";
static char       string[64];

void heatmap_toggle() { heatmap_enabled = !heatmap_enabled; }

void heatmap_reset() {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        keycount[i]      = 0;
        disabled_keys[i] = false;
    }

    max = min = 0;
}

void dump_counts_of_pad(uint16_t* pad) {
    for (int i = 0; i < DRIVER_LED_TOTAL / 2; i++) {
        itoa(pad[i], string, 10);
        SEND_STRING(string);
        SEND_STRING(separator);
    }
    SEND_STRING("\n");
}

void dump_disabled_of_pad(bool* pad) {
    for (int i = 0; i < DRIVER_LED_TOTAL / 2; i++) {
        itoa(pad[i], string, 10);
        SEND_STRING(string);
        SEND_STRING(separator);
    }
    SEND_STRING("\n");
}

void heatmap_dump() {
    char separator[] = " ";
    char string[64];
    SEND_STRING("count\n");
    dump_counts_of_pad(keycount);
    dump_counts_of_pad(&keycount[DRIVER_LED_TOTAL / 2]);
    SEND_STRING("disabled\n");
    dump_disabled_of_pad(disabled_keys);
    dump_disabled_of_pad(&disabled_keys[DRIVER_LED_TOTAL / 2]);

    SEND_STRING("Heatmap ");
    if (heatmap_enabled) {
        SEND_STRING("enabled");
    } else {
        SEND_STRING("disabled");
    }

    itoa(min, string, 10);
    SEND_STRING("\nmin, max ");
    SEND_STRING(string);
    SEND_STRING(separator);
    itoa(max, string, 10);
    SEND_STRING(string);
    SEND_STRING("\n");
}

int keypos_to_index(keypos_t key) {
    /* Left thumb pad. */
    if (key.row == 5) {
        return 32 + key.col;
    }
    /* Left key pad. */
    if (key.row < 5) {
        int i = 5 * key.col + key.row;
        if (i > 28) i--;
        return i;
    }

    /* Right thumb pad. */
    if (key.row == 11) {
        return 68 + (6 - key.col);
    }

    /* Right key pad. */
    // else: key.row < 11
    int i = 36 + 5 * (6 - key.col) + key.row - 6;
    if (i > 64) i--;
    return i;
}

void handle_overflow(void) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (keycount[i] == 0) {
            disabled_keys[i] = true;
        } else {
            keycount[i] >>= 1;
        }
    }

    max >>= 1;
    min >>= 1;
}

void update_extremes(void) {
    max = 0;
    min = UINT16_MAX;

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (keycount[i] < min && keycount[i] > 0) {
            min = keycount[i];
        }

        if (keycount[i] > max) {
            max = keycount[i];
        }
    }

    if (min > max) {
        min = max;
    }
}

void heatmap_process(keypos_t key) {
    int i = keypos_to_index(key);
    if (keycount[i] == UINT16_MAX) handle_overflow();

    if (!disabled_keys[i]) {
        bool update_required = min == keycount[i] || max == keycount[i];

        keycount[i]++;

        if (update_required) {
            update_extremes();
        }
    }
}

/*
 * Color calculation uses a simple sigmoid function:
 * 0 == count: black.
 * 0 < count < min: violet.
 * min <= count < max: logarithmic color gradient from violet to red.
 */
HSV calc_color(int index) {
    const uint8_t violet = 180; /* Used as color for min2 and below. */
    const uint8_t red    = 0;   /* Used for max2 and above. */

    double_t      hue    = 0;

    if (keycount[index] > 0) {
        /* Calculate differences first to get numbers in low ranges to avoid rounding errors. */
        double diff  = log(max) - log(keycount[index]);
        double range = log(max) - log(min);

        /* Avoid division by zero. */
        if (range == 0 || diff == 0) {
            hue = red;
        } else {
            hue = (double)violet * ((double)diff / (double)range) + red;
        }
    }

    HSV color = {(int8_t)hue, 255, 255};
    if (keycount[index] == 0 || disabled_keys[index]) {
        color.v = 0;
    }

    return color;
}

bool heatmap_render(void) {
    if (heatmap_enabled) {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
            if (max == 0) {
                const HSV black = {HSV_BLACK};
                rgb_matrix_set_hsv(i, black);
            }
            rgb_matrix_set_hsv(i, calc_color(i));
        }
    }

    return heatmap_enabled;
}
