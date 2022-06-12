#pragma once
#include QMK_KEYBOARD_H


/* Ensure that range for custom operation is aligned with next free ..0 boundary
 * to allow arguments to be pushed to the lower byte.
 * 24065/0x5E00 */
#define TN_OP_RANGE_START ((ML_SAFE_RANGE & ~0xff) + 0x100)

#define TN_MULTI_ONESHOT_LAYER TN_OP_RANGE_START

/* 24320/0x5F00 */
#define TN_CTRL_DANCE (TN_MULTI_ONESHOT_LAYER + 0x100)

/* ATTENTION: Will overwrite original LT()/TT() action codes when used */
/* We need a range in which the lowest 3 nibbles are free. */
//#define TN_FAST_LAYER_TAP QK_LAYER_TAP


/* Define safe range for custom keycodes to start after custom action range. */
#define TN_SAFE_RANGE (TN_FAST_LAYER_TAP + 0x1000)

#define MOSL(layer) (TN_MULTI_ONESHOT_LAYER | ((layer)&0xFF))
#define CD(keycode) (TN_CTRL_DANCE | ((keycode)&0xFF))

#ifdef TN_FAST_LAYER_TAP
#define FLT(layer, keycode) (TN_FAST_LAYER_TAP | (((layer)&0x0F) << 8) | ((keycode)&0xFF))
#endif

typedef enum custom_action_result { not_processed, consumed, processed} custom_action_result_t;

custom_action_result_t process_custom_action(uint16_t keycode, keyrecord_t* record);
