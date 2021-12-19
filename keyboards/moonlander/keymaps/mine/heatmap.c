#include "heatmap.h"
#include "rgb_matrix_utils.h"

static uint16_t keycount[DRIVER_LED_TOTAL];
static bool     disabled_keys[DRIVER_LED_TOTAL];
static uint16_t max, min;
static bool     heatmap_enabled = false;

void heatmap_toggle() { heatmap_enabled = !heatmap_enabled; }

void heatmap_reset() {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        keycount[i]      = 0;
        disabled_keys[i] = false;
    }

    max = min = 0;
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
    // if (key.row < 11) {
    int i = 36 + 5 * (6 - key.col) + key.row - 6;
    if (i > 64) i--;
    return i;
    //}
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

uint16_t get_min_count(void) {
    uint16_t result = UINT16_MAX;

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (result > keycount[i] && keycount[i] > 0) {
            result = keycount[i];
        }
    }

    return result;
}

void heatmap_process(keypos_t key) {
    int i = keypos_to_index(key);
    if (keycount[i] == UINT16_MAX) handle_overflow();

    if (!disabled_keys[i]) {
        bool update_min = min == keycount[i];

        keycount[i]++;

        if (max < keycount[i]) {
            max++;
        }
        if (min > keycount[i]) {
            min = keycount[i];
        }
        if (update_min) {
            min = get_min_count();
        }
    }
}

HSV calc_color(int index) {
    /* 180: hue of violet. Used as color for min.
     * 0: hue of red. Used as color for max.
     */

    /* Calculate differences first to get numbers in low ranges to avoid rounding errors. */
    uint16_t diff  = max - keycount[index];
    uint16_t range = max - min;
    double_t hue   = 0;

    /* Avoid division by zero. */
    if (range == 0 || diff == 0) {
        hue = 0;
    } else {
        hue = 180 * ((double)diff / (double)range);
    }
    HSV color = {(int)hue, 255, 255};
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
