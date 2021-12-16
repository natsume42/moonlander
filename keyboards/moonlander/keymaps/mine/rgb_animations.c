#include "rgb_animations.h"

bool inline hit_upper_boundary(uint8_t upper_boundary, uint8_t current_value, uint8_t step_size) {
    return upper_boundary - current_value <= step_size;
}

bool inline hit_lower_boundary(uint8_t lower_boundary, uint8_t current_value, uint8_t step_size) {
    return current_value - lower_boundary <= step_size;
}

bool is_in_range(uint8_t low, uint8_t high, uint8_t value);
bool inline is_in_range(uint8_t low, uint8_t high, uint8_t value) {
    return (low < high && (low <= value && value <= high))
        || (high <= value && value <= low);
}

bool is_timer_elapsed(uint16_t start_time, uint16_t now, uint16_t delay) {
    return start_time > now || now - start_time > delay;
}

HSV rgb_step_breathe(HSV color, uint16_t delay, uint8_t step_size) {
    static uint16_t start_time;
    static uint8_t  breathe_val;
    static bool     raise;

    uint16_t now = timer_read();
    if (is_timer_elapsed(start_time, now, delay)) {
        start_time = now;

        if (raise && hit_upper_boundary(0xff, breathe_val, step_size)) {
            raise       = false;
            breathe_val = 0xff;
        } else if (!raise && hit_lower_boundary(0, breathe_val, step_size)) {
            raise       = true;
            breathe_val = 0;
        } else if (raise) {
            breathe_val += step_size;
        } else {
            breathe_val -= step_size;
        }
    }

    color.v = breathe_val;
    return color;
}

HSV rgb_step_rainbow(HSV color, uint16_t delay, uint8_t step_size) {
    static uint16_t start_time;
    static uint8_t  rainbow_hue;

    uint16_t now = timer_read();
    if (is_timer_elapsed(start_time, now, delay)) {
        start_time = now;

        rainbow_hue += step_size;
    }

    color.h = rainbow_hue;
    return color;
}

HSV rgb_step_hue_gradient(HSV from_color, HSV to_color, uint16_t delay, uint8_t step_size) {
    static uint16_t start_time;
    static uint8_t  hue;
    static bool     raise;

    uint16_t now = timer_read();
    if (is_timer_elapsed(start_time, now, delay)) {
        start_time = now;

        if ((raise && hit_upper_boundary(to_color.h, hue, step_size))
            || !is_in_range(from_color.h, to_color.h, hue)) {
            raise       = false;
            hue = to_color.h;
        } else if (!raise && hit_lower_boundary(from_color.h, hue, step_size)) {
            raise       = true;
            hue = from_color.h;
        } else if (raise) {
            hue += step_size;
        } else {
            hue -= step_size;
        }
    }

    to_color.h = hue;
    return to_color;
}
