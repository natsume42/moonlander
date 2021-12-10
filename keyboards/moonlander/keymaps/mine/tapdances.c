#include "tapdances.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

static tap dance_state[35];

uint8_t dance_step(qk_tap_dance_state_t *state) { 
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if (state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code16(DE_CIRC);
            break;
        case DOUBLE_TAP:
            register_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            register_code16(LALT(KC_F4));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code16(DE_CIRC);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LALT(KC_F4));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
    }
    dance_state[0].step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if (state->count > 3) {
        tap_code16(KC_1);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_1);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_1));
            break;
        case DOUBLE_TAP:
            register_code16(KC_1);
            register_code16(KC_1);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_1));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_1);
            register_code16(KC_1);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_1);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_1));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_1);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_1));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_1);
            break;
    }
    dance_state[1].step = 0;
}

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if (state->count > 3) {
        tap_code16(KC_2);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_2);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_2));
            break;
        case DOUBLE_TAP:
            register_code16(KC_2);
            register_code16(KC_2);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_2));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_2);
            register_code16(KC_2);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_2);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_2));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_2);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_2));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_2);
            break;
    }
    dance_state[2].step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if (state->count > 3) {
        tap_code16(KC_3);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_3);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_3));
            break;
        case DOUBLE_TAP:
            register_code16(KC_3);
            register_code16(KC_3);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_3));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_3);
            register_code16(KC_3);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_3);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_3));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_3);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_3));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_3);
            break;
    }
    dance_state[3].step = 0;
}

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if (state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(KC_4);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_4));
            break;
        case DOUBLE_TAP:
            register_code16(KC_4);
            register_code16(KC_4);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_4));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_4);
            register_code16(KC_4);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(KC_4);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_4));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_4);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_4));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_4);
            break;
    }
    dance_state[4].step = 0;
}

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if (state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            register_code16(KC_5);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_5));
            break;
        case DOUBLE_TAP:
            register_code16(KC_5);
            register_code16(KC_5);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_5);
            register_code16(KC_5);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            unregister_code16(KC_5);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_5));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_5);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_5);
            break;
    }
    dance_state[5].step = 0;
}

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if (state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            register_code16(KC_ENTER);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_ENTER));
            break;
        case DOUBLE_TAP:
            register_code16(KC_ENTER);
            register_code16(KC_ENTER);
            break;
        case DOUBLE_HOLD:
            register_code16(LSFT(KC_ENTER));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ENTER);
            register_code16(KC_ENTER);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ENTER);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_ENTER));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ENTER);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LSFT(KC_ENTER));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ENTER);
            break;
    }
    dance_state[6].step = 0;
}

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if (state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            register_code16(KC_6);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_6));
            break;
        case DOUBLE_TAP:
            register_code16(KC_6);
            register_code16(KC_6);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_6));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_6);
            register_code16(KC_6);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            unregister_code16(KC_6);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_6));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_6);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_6));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_6);
            break;
    }
    dance_state[7].step = 0;
}

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if (state->count > 3) {
        tap_code16(KC_7);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_7);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_7));
            break;
        case DOUBLE_TAP:
            register_code16(KC_7);
            register_code16(KC_7);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_7));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_7);
            register_code16(KC_7);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_7);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_7));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_7);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_7));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_7);
            break;
    }
    dance_state[8].step = 0;
}

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if (state->count > 3) {
        tap_code16(KC_8);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            register_code16(KC_8);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_8));
            break;
        case DOUBLE_TAP:
            register_code16(KC_8);
            register_code16(KC_8);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_8));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_8);
            register_code16(KC_8);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            unregister_code16(KC_8);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_8));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_8);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_8));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_8);
            break;
    }
    dance_state[9].step = 0;
}

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if (state->count > 3) {
        tap_code16(KC_9);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            register_code16(KC_9);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_9));
            break;
        case DOUBLE_TAP:
            register_code16(KC_9);
            register_code16(KC_9);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(KC_9));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_9);
            register_code16(KC_9);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            unregister_code16(KC_9);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_9));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_9);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(KC_9));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_9);
            break;
    }
    dance_state[10].step = 0;
}

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if (state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            register_code16(KC_0);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_0));
            break;
        case DOUBLE_TAP:
            register_code16(KC_0);
            register_code16(KC_0);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_0);
            register_code16(KC_0);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            unregister_code16(KC_0);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_0));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_0);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_0);
            break;
    }
    dance_state[11].step = 0;
}

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if (state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            register_code16(KC_COMMA);
            break;
        case SINGLE_HOLD:
            register_code16(DE_SCLN);
            break;
        case DOUBLE_TAP:
            register_code16(KC_COMMA);
            register_code16(KC_COMMA);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_COMMA);
            register_code16(KC_COMMA);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            unregister_code16(KC_COMMA);
            break;
        case SINGLE_HOLD:
            unregister_code16(DE_SCLN);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_COMMA);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_COMMA);
            break;
    }
    dance_state[12].step = 0;
}

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if (state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            register_code16(DE_COLN);
            break;
        case DOUBLE_TAP:
            register_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOT);
            register_code16(KC_DOT);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(DE_COLN);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
    }
    dance_state[13].step = 0;
}

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if (state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            register_code16(KC_DELETE);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_DELETE));
            break;
        case DOUBLE_TAP:
            register_code16(KC_DELETE);
            register_code16(KC_DELETE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DELETE);
            register_code16(KC_DELETE);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DELETE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_DELETE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DELETE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DELETE);
            break;
    }
    dance_state[14].step = 0;
}

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
        tap_code16(KC_KP_ASTERISK);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_ASTERISK);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_ASTERISK);
            break;
        case SINGLE_HOLD:
            register_code16(KC_KP_SLASH);
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_ASTERISK);
            register_code16(KC_KP_ASTERISK);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_ASTERISK);
            register_code16(KC_KP_ASTERISK);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_ASTERISK);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_KP_SLASH);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_ASTERISK);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_ASTERISK);
            break;
    }
    dance_state[15].step = 0;
}

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_PLUS);
        tap_code16(KC_KP_PLUS);
        tap_code16(KC_KP_PLUS);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_PLUS);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_PLUS);
            break;
        case SINGLE_HOLD:
            register_code16(KC_KP_MINUS);
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_PLUS);
            register_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_PLUS);
            register_code16(KC_KP_PLUS);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_KP_MINUS);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
    }
    dance_state[16].step = 0;
}

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_ENTER);
        tap_code16(KC_KP_ENTER);
        tap_code16(KC_KP_ENTER);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_ENTER);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_ENTER);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_ENTER));
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_ENTER);
            register_code16(KC_KP_ENTER);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_ENTER);
            register_code16(KC_KP_ENTER);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_ENTER);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_ENTER));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_ENTER);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_ENTER);
            break;
    }
    dance_state[17].step = 0;
}

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if (state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            register_code16(KC_COMMA);
            break;
        case SINGLE_HOLD:
            register_code16(KC_DOT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_COMMA);
            register_code16(KC_COMMA);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_COMMA);
            register_code16(KC_COMMA);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            unregister_code16(KC_COMMA);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_DOT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_COMMA);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_COMMA);
            break;
    }
    dance_state[18].step = 0;
}

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if (state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            register_code16(KC_F);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F);
            register_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F);
            register_code16(KC_F);
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F);
            break;
    }
    dance_state[19].step = 0;
}

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if (state->count > 3) {
        tap_code16(KC_R);
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            register_code16(KC_R);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            register_code16(KC_R);
            register_code16(KC_R);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_R);
            register_code16(KC_R);
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            unregister_code16(KC_R);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_R);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_R);
            break;
    }
    dance_state[20].step = 0;
}

void on_dance_21(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if (state->count > 3) {
        tap_code16(KC_B);
    }
}

void dance_21_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            register_code16(KC_B);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            register_code16(KC_B);
            register_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_B);
            register_code16(KC_B);
    }
}

void dance_21_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            unregister_code16(KC_B);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_B);
            break;
    }
    dance_state[21].step = 0;
}

void on_dance_22(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if (state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_22_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            register_code16(KC_U);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            register_code16(KC_U);
            register_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_U);
            register_code16(KC_U);
    }
}

void dance_22_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            unregister_code16(KC_U);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_U);
            break;
    }
    dance_state[22].step = 0;
}

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F12);
        tap_code16(KC_F12);
        tap_code16(KC_F12);
    }
    if (state->count > 3) {
        tap_code16(KC_F12);
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            register_code16(KC_F12);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F12));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F12);
            register_code16(KC_F12);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F12);
            register_code16(KC_F12);
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F12);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F12));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F12);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F12);
            break;
    }
    dance_state[23].step = 0;
}

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if (state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            register_code16(KC_F7);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F7));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F7);
            register_code16(KC_F7);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F7);
            register_code16(KC_F7);
    }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F7);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F7));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F7);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F7);
            break;
    }
    dance_state[24].step = 0;
}

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if (state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            register_code16(KC_F8);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F8));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F8);
            register_code16(KC_F8);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F8);
            register_code16(KC_F8);
    }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F8);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F8));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F8);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F8);
            break;
    }
    dance_state[25].step = 0;
}

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if (state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            register_code16(KC_F9);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F9));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F9);
            register_code16(KC_F9);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F9);
            register_code16(KC_F9);
    }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F9);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F9));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F9);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F9);
            break;
    }
    dance_state[26].step = 0;
}

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F11);
        tap_code16(KC_F11);
        tap_code16(KC_F11);
    }
    if (state->count > 3) {
        tap_code16(KC_F11);
    }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            register_code16(KC_F11);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F11));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F11);
            register_code16(KC_F11);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F11);
            register_code16(KC_F11);
    }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F11);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F11));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F11);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F11);
            break;
    }
    dance_state[27].step = 0;
}

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if (state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            register_code16(KC_F4);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F4));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F4);
            register_code16(KC_F4);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F4);
            register_code16(KC_F4);
    }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F4);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F4));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F4);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F4);
            break;
    }
    dance_state[28].step = 0;
}

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if (state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            register_code16(KC_F5);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F5));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F5);
            register_code16(KC_F5);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F5);
            register_code16(KC_F5);
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F5);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F5));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F5);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F5);
            break;
    }
    dance_state[29].step = 0;
}

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if (state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP:
            register_code16(KC_F6);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F6));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F6);
            register_code16(KC_F6);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F6);
            register_code16(KC_F6);
    }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F6);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F6));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F6);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F6);
            break;
    }
    dance_state[30].step = 0;
}

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if (state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP:
            register_code16(KC_F10);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F10));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F10);
            register_code16(KC_F10);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F10);
            register_code16(KC_F10);
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F10);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F10));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F10);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F10);
            break;
    }
    dance_state[31].step = 0;
}

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if (state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP:
            register_code16(KC_F1);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F1));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F1);
            register_code16(KC_F1);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F1);
            register_code16(KC_F1);
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F1);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F1));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F1);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F1);
            break;
    }
    dance_state[32].step = 0;
}

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if (state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP:
            register_code16(KC_F2);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F2));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F2);
            register_code16(KC_F2);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F2);
            register_code16(KC_F2);
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F2);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F2));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F2);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F2);
            break;
    }
    dance_state[33].step = 0;
}

void on_dance_34(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if (state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_34_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP:
            register_code16(KC_F3);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F3));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F3);
            register_code16(KC_F3);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F3);
            register_code16(KC_F3);
    }
}

void dance_34_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F3);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F3));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F3);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F3);
            break;
    }
    dance_state[34].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),     [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),     [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),     [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),     [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),     [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),     [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),     [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),     [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),     [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset), [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset), [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset), [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset), [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset), [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset), [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset), [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
    [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset), [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset), [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset), [DANCE_21] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset), [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset), [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset), [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset), [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset), [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
    [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset), [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset), [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset), [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset), [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset), [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset), [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset), [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
};
