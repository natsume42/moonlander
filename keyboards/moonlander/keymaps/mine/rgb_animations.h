#pragma once
#include QMK_KEYBOARD_H

HSV rgb_step_breathe(HSV color, uint16_t delay, uint8_t step_size);
HSV rgb_step_rainbow(HSV color, uint16_t delay, uint8_t step_size);
HSV rgb_step_hue_gradient(HSV from_color, HSV to_color, uint16_t delay, uint8_t step_size);

typedef struct _toggle_data {
    HSV      color1;
    uint16_t delay1;
    HSV      color2;
    uint16_t delay2;

    /* Internal state. */
    bool     use_color1;
    uint16_t start_time;
} toggle_data;

HSV rgb_step_toggle(toggle_data* data);
