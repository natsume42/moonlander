#include "custom_actions.h"
#include "oneshot.h"
#include "ctrl_dance.h"
#include "fast_layer_tap.h"

custom_action_result_t process_custom_action(uint16_t keycode, keyrecord_t* record) {
    int actioncode = keycode & ~0xff;
    int arg        = keycode & 0xff;

    interrupt_ctrl_dance_on_different_key(arg);

#ifdef TN_FAST_LAYER_TAP
    if (fast_layer_switch_when_armed(record)) {
        keycode    = get_event_keycode(record->event, true);
        actioncode = keycode & ~0xff;
        arg        = keycode & 0xff;
    }
#endif

    switch (actioncode) {
        case TN_MULTI_ONESHOT_LAYER:
            process_oneshot_key(arg, record);
            return processed;
            break;
        case TN_CTRL_DANCE:
            process_ctrl_dance(arg, record);
            return processed;
            break;
    }

#ifdef TN_FAST_LAYER_TAP
    int     actioncode2 = keycode & ~0xfff;
    int     args        = keycode & 0xfff;
    uint8_t layer       = args >> 8;
    uint8_t kc          = args & 0xff;

    dprintf("keycode:  %u\n",  keycode);
    dprintf("actioncode2:  %u\n",  actioncode2);
    dprintf("TN_FAST_LAYER_TAP:  %u\n",  TN_FAST_LAYER_TAP);

    switch (actioncode2) {
        case TN_FAST_LAYER_TAP:
            process_fast_layer_tap(layer, kc, record);
            return consumed;
            break;
    }
#endif

    return not_processed;
}
