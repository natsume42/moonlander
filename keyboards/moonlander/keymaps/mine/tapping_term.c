#include QMK_KEYBOARD_H
#include "layers.h"
#include "custom_actions/custom_actions.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    //const uint16_t long_term = TAPPING_TERM + 200;
    const uint16_t medium_term = TAPPING_TERM + 150;
    switch (keycode) {
        case CD(KC_A) ... CD(KC_Z):
            return medium_term;

        case LCTL_T(KC_R):
        case LGUI_T(KC_I):
        case LALT_T(KC_E):
        case LCTL_T(KC_N):
        case LGUI_T(KC_T):
        case LALT_T(KC_S):
            return medium_term;

        default:
            return TAPPING_TERM;
    }
}
