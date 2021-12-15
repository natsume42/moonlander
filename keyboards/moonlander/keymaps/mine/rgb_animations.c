#include "rgb_animations.h"

HSV rgb_step_breathe(HSV color, uint16_t delay, uint8_t step_size) {
    static uint16_t start_time;
    static uint8_t  breathe_val;
    static bool     raise;

    uint16_t now = timer_read();
    if (start_time > now || now - start_time > delay) {
        start_time = now;

        if (raise && (0xff - breathe_val < step_size)) {
            dprintf("peak: start_time: %d, breathe_val: %d\n", start_time, now, breathe_val);
            raise       = false;
            breathe_val = 0xff;
        }
        if (!raise && (breathe_val < step_size)) {
            raise       = true;
            breathe_val = 0;
        }

        if (raise) {
            breathe_val += step_size;
        } else {
            breathe_val -= step_size;
        }
    }

    color.v = breathe_val;
    return color;
}
