#include "heatmap.h"
#include "rgb_matrix_utils.h"

static uint16_t keycount[DRIVER_LED_TOTAL];
static bool     disabled_keys[DRIVER_LED_TOTAL];
static uint16_t max, min, max2, min2;
static bool     heatmap_enabled = false;

void heatmap_toggle() { heatmap_enabled = !heatmap_enabled; }

void heatmap_reset() {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        keycount[i]      = 0;
        disabled_keys[i] = false;
    }

    max = min = max2 = min2 = 0;
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
    max = max2 = 0;
    min = min2 = UINT16_MAX;

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (min > keycount[i] && keycount[i] > 0) {
            min2 = min;
            min = keycount[i];
        }

        if (max < keycount[i]) {
            max2 = max;
            max  = keycount[i];
        }
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
 * 0 <= count < min2: constant violet.
 * min2 <= count < max2: linear color gradient from violet to red.
 * max2 > count: constant red.
 *
 * min2/max2 are used instead of min/max to cut of extrem outliers like SPACE
 * key, which is used much more frequent than any other key and would therefore
 * cause a "blue shift" of all "regular" keys (letters).
 * From a mathematical point of view using 10%/90% quantile would be a better,
 * choice but their calculation was deemed to be too expensive in terms of 
 * resource consumption. 
 */
HSV calc_color(int index) {
    const uint8_t violet = 180; /* Used as color for min2 and below. */
    const uint8_t red    = 0;   /* Used for max2 and above. */

    /* Calculate differences first to get numbers in low ranges to avoid rounding errors. */
    uint16_t low   = (double)min2;
    uint16_t high  = (double)max2;
    uint16_t diff  = high - keycount[index];
    uint16_t range = high - low;
    double_t hue   = 0;
    
    /* Avoid division by zero. */
    if (range == 0 || diff == 0 || keycount[index] > high) {
        hue = red;
    } else {
        if (keycount[index] < low) {
            hue = violet;
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