#include "languages.h"

void switch_to_japanese(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))) SS_DELAY(100) SS_TAP(X_INT2));
    layer_move(5);
}

void switch_to_german(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_1))));
    layer_move(0);
}
