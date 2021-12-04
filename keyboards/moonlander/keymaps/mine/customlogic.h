/** \brief Change input language and keyboard layer to Japanese input.
* 
* ALT+Shift+2 to switch to Japanese IME
* INT2 (Hiragana key on Japanese keyboard) to switch to Hiragana
* Switch to JISX6004 layer.
*/
void switch_to_japanese(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))) SS_DELAY(100) SS_TAP(X_INT2));
    layer_move(5);
}

/** \brief Change input language and keyboard layer to German input.
 * 
 * ALT+Shift+1 to switch to Japanese IME
 * Switch to Mine layer.
 */
void switch_to_german(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_1))));
    layer_move(0);
}
