#include "fast_layer_tap.h"

static uint8_t fast_layer     = 0;
static bool    layer_switched = false;
static bool    is_same_layer  = false;

void process_fast_layer_tap(uint8_t layer, uint8_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (record->tap.count < 3) {
            fast_layer = layer;
        } else {
            register_code16(keycode);
        }
    } else {
        fast_layer = 0;

        if (layer_switched) {
            if (!is_same_layer) {
                layer_off(layer);
            }
            is_same_layer  = false;
            layer_switched = false;
        } else {
            if (record->tap.count < 3) {
                tap_code16(keycode);
            } else {
                unregister_code16(keycode);
            }
        }
    }
}

bool is_fast_layer_armed(void) { return fast_layer != 0; }

bool fast_layer_switch_when_armed(keyrecord_t *record) {
    if (is_fast_layer_armed() && record->event.pressed && !layer_switched) {
        if (IS_LAYER_ON(fast_layer)) {
            is_same_layer = true;
        }

        layer_on(fast_layer);
        layer_switched = true;
        return true;
    }

    return false;
}
