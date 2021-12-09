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

void process_oneshot_key(uint8_t layer, keyrecord_t *record) {
    if (record->event.pressed) {
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
