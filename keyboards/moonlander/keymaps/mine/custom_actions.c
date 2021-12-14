#include "custom_actions.h"
#include "oneshot.h"

bool process_custom_action(uint16_t keycode, keyrecord_t* record) {
    int actioncode = keycode & ~0xff;
    int arg        = keycode & 0xff;

    if (actioncode == TN_MULTI_ONESHOT_LAYER) {
        process_oneshot_key(arg, record);
        return false;
    }
    return true;
}
