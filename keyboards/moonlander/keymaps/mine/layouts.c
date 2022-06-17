#include "layouts.h"
#include "layers.h"

void switch_to_mine(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_1))));
    default_layer_set(1UL << mineL | 1UL << commonL);
    default_layer_move();
}

void switch_to_jisx6004(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))) SS_DELAY(200) SS_TAP(X_INT2));
    default_layer_set(1UL << ja1L | 1UL << commonL);
    default_layer_move();
}

void default_layer_move(void) { layer_state_set(default_layer_state); }
