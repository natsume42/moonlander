#pragma once
#include QMK_KEYBOARD_H


/* Ensure that range for custom operation is aligned with next free 0x..00 boundary
 * to allow arguments to be pushed to the lower byte. */
#define TN_OP_RANGE_START ((ML_SAFE_RANGE & ~0xff) + 0x100)

#define TN_FAST_ONESHOT_LAYER TN_OP_RANGE_START

/* Define safe range for custom keycodes to start after custom action range. */
#define TN_SAFE_RANGE (TN_FAST_ONESHOT_LAYER + 0x100)

#define FOSL(layer) (TN_FAST_ONESHOT_LAYER | ((layer)&0xFF))

bool process_custom_action(uint16_t keycode, keyrecord_t* record);
