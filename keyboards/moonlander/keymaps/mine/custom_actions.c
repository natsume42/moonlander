#include "custom_actions.h"
#include "oneshot.h"
#include "ctrl_dance.h"

bool process_custom_action(uint16_t keycode, keyrecord_t* record) {
    int actioncode = keycode & ~0xff;
    int arg        = keycode & 0xff;

    interrupt_ctrl_dance_on_different_key(arg);

    if (actioncode == TN_MULTI_ONESHOT_LAYER) {
        process_oneshot_key(arg, record);
        return false;
    } else if (actioncode == TN_CTRL_DANCE) {
        process_ctrl_dance(arg, record);
        return false;
    }
    return true;
}
