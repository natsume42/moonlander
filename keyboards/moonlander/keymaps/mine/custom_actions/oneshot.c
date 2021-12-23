#include "oneshot.h"

void process_oneshot_key(uint8_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
        /* To allow chaining OSL macros, clear already active one shot layer, if any.
         * This ensures that we return to first non-OSL after (last) OSL has finished.
         * We use clear_oneshot_layer_state() instead of reset_oneshot_layer(),
         * because the latter does no layer_off for the active OSL but just resets
         * the OSL related states.
         */
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);

        set_oneshot_layer(layer, ONESHOT_START);

        /* Workaround:
         * By setting pressed to false, we prevent framework logic(process_action)
         * from clearing ONESHOT_OTHER_KEY_PRESSED already for our OSL key, which would cause
         * the OSL to be cleared as soon as the key release event gets processed and
         * we would therefore never get a chance to hit a key on the OSL.
         */
        record->event.pressed = false;
    } else {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}
