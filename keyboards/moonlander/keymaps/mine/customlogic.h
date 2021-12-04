/** Change input language and keyboard layer to Japanese input.
* ALT+Shift+2 to switch to Japanese IME
* INT2 (Hiragana key on Japanese keyboard) to switch to Hiragana
* Switch to JISX6004 layer.
*/
void switch_to_japanese(void) {
    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))) SS_DELAY(100) SS_TAP(X_INT2));
    layer_move(5);
}
