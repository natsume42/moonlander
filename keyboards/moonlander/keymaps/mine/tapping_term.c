#include QMK_KEYBOARD_H
#include "layers.h"
#include "custom_actions/custom_actions.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    const uint16_t long_term = TAPPING_TERM + 1000;
    const uint16_t medium_term = TAPPING_TERM + 150;
    switch (keycode) {
        case LT(numPadL, KC_SPACE):
            return long_term;
        case CD(KC_A) ... CD(KC_Z):
            return medium_term;
        default:
            return TAPPING_TERM;
    }
}
