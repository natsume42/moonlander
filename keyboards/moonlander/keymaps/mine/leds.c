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

    switch (state) {
        case (1UL << mineL)...(1UL << ja1L) - 1:
            break;
        case (1UL << ja1L)...(1UL << ja2L) - 1:
        case (1UL << ja2L)...(1UL << qwertzL) - 1:
            ML_LED_3(true);
            break;
        case (1UL << qwertzL)...(1UL << editL) - 1 :
            ML_LED_2(true);
            break;
        case (1UL << editL)...(1UL << numPadL) - 1 :
            ML_LED_6(true);
            break;
        case (1UL << numPadL)...(1UL << prgSymL) - 1 :
            ML_LED_1(true);
            ML_LED_5(num_lock);
            break;
        default:
            break;
    }

    // Ensure that our led settings do not get overwritten by moonlander logic.
    keyboard_config.led_level = false;

    return state;
}
