#pragma once
#include QMK_KEYBOARD_H

HSV rgb_step_breathe(HSV color, uint16_t delay, uint8_t step_size);
HSV rgb_step_rainbow(HSV color, uint16_t delay, uint8_t step_size);
