#pragma once
#include QMK_KEYBOARD_H

void process_fast_layer_tap(uint8_t layer, uint8_t keycode, keyrecord_t *record);
bool fast_layer_switch_when_armed(keyrecord_t *record);
