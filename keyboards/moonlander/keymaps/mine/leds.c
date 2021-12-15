#include QMK_KEYBOARD_H
#include "layers.h"
extern bool mcp23018_leds[3];

bool num_lock = true;

bool led_update_user(led_t state) {
    if ((1UL << numPadL) <= layer_state && layer_state < (1UL << prgSymL)) {
        num_lock = state.num_lock;
        ML_LED_5(num_lock);
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    if (layer_state_cmp(state, ja1L) || layer_state_cmp(state, ja2L)) {
        ML_LED_3(true);
    } else if (layer_state_cmp(state, qwertzL)) {
        ML_LED_2(true);
    } else if (layer_state_cmp(state, editL)) {
        ML_LED_6(true);
    } else if (layer_state_cmp(state, numPadL)) {
        ML_LED_1(true);
        ML_LED_5(num_lock);
    }

    // Ensure that our led settings do not get overwritten by moonlander logic.
    keyboard_config.led_level = false;

    return state;
}
