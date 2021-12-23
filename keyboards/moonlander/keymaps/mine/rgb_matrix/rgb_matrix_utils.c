#include "rgb_matrix_utils.h"

void rgb_matrix_set_hsv(int led_pos, HSV hsv) {
    // HSV   hsv = {.h = hue, .s = sat, .v = val};
    RGB   rgb = hsv_to_rgb(hsv);
    float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(led_pos, f * rgb.r, f * rgb.g, f * rgb.b);
}
