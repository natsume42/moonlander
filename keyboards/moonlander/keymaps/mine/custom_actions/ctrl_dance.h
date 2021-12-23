#pragma once
#include QMK_KEYBOARD_H

void process_ctrl_dance(uint8_t keycode, keyrecord_t *record);
void interrupt_ctrl_dance_on_different_key(uint8_t keycode);
