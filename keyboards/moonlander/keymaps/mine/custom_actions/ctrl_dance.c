#include "ctrl_dance.h"
#include "custom_actions.h"

static uint16_t ctrl_dance_start_time;
static uint8_t  ctrl_dance_keycode;

void reset_ctrl_dance(void) {
    ctrl_dance_keycode    = 0;
    ctrl_dance_start_time = 0;
}

bool within_tapping_term(uint16_t time, uint8_t keycode) {
    return time - ctrl_dance_start_time < get_tapping_term(CD(keycode), NULL);
}

void process_ctrl_dance(uint8_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        ctrl_dance_start_time = record->event.time;
        ctrl_dance_keycode    = keycode;
    } else if (ctrl_dance_keycode == keycode) {
        if (within_tapping_term(record->event.time, keycode)) {
            tap_code16(keycode);
        } else {
            tap_code16(LCTL(keycode));
        }
        reset_ctrl_dance();
    }
}

void interrupt_ctrl_dance_on_different_key(uint8_t keycode) {
    if (keycode != ctrl_dance_keycode && ctrl_dance_keycode != 0) {
        tap_code16(ctrl_dance_keycode);
        reset_ctrl_dance();
    }
}
