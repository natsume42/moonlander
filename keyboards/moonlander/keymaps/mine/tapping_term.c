#include QMK_KEYBOARD_H
#include "layers.h"
#include "tapdances.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    const uint16_t long_term = TAPPING_TERM + 1000;
    switch (keycode) {
        case LT(numPadL, KC_SPACE):
            return long_term;
        default:
            return TAPPING_TERM;
    }
}
