#include "layouts.h"
#include "layers.h"

void switch_to_jisx6004(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))) SS_DELAY(200) SS_TAP(X_INT2));
    layer_move(ja1L);
    //default_layer_set(1UL << ja1L);
}

void switch_to_mine(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_1))));
    layer_move(mineL);
    //default_layer_set(1UL << mineL);
}
