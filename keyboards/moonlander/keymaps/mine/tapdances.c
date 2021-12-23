#include "tapdances.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

#include "rgb_matrix/heatmap.h"

static tap dance_state[LAST_DANCE];

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
        case DOUBLE_TAP:
            register_code16(LCTL(KC_F4));
            break;
        case DOUBLE_HOLD:
            register_code16(LALT(KC_F4));
            break;
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case DOUBLE_TAP:
            unregister_code16(LCTL(KC_F4));
            break;
        case DOUBLE_HOLD:
            unregister_code16(LALT(KC_F4));
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
    dance_state[DANCE_11].step = dance_step(state);
    switch (dance_state[DANCE_11].step) {
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
    switch (dance_state[DANCE_11].step) {
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
    dance_state[DANCE_11].step = 0;
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
    dance_state[DANCE_19].step = dance_step(state);
    switch (dance_state[DANCE_19].step) {
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
    switch (dance_state[DANCE_19].step) {
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
    dance_state[DANCE_19].step = 0;
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
    dance_state[DANCE_20].step = dance_step(state);
    switch (dance_state[DANCE_20].step) {
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
    switch (dance_state[DANCE_20].step) {
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
    dance_state[DANCE_20].step = 0;
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
    dance_state[DANCE_21].step = dance_step(state);
    switch (dance_state[DANCE_21].step) {
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
    switch (dance_state[DANCE_21].step) {
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
    dance_state[DANCE_21].step = 0;
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
    dance_state[DANCE_22].step = dance_step(state);
    switch (dance_state[DANCE_22].step) {
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
    switch (dance_state[DANCE_22].step) {
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
    dance_state[DANCE_22].step = 0;
}

void on_dance_heatmap(qk_tap_dance_state_t *state, void *user_data) {}

void dance_heatmap_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[HEATMAP_DANCE].step = dance_step(state);
    switch (dance_state[HEATMAP_DANCE].step) {
        case SINGLE_TAP:
            heatmap_toggle();
            break;
        case DOUBLE_HOLD:
            heatmap_reset();
            break;
    }
}

void dance_heatmap_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[HEATMAP_DANCE].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_4]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [DANCE_5]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [DANCE_7]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [DANCE_8]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [DANCE_9]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    [DANCE_10]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    [DANCE_11]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
    [MULT_DIV]      = ACTION_TAP_DANCE_DOUBLE(KC_KP_ASTERISK, MULT_DIV),
    [PLUS_MINUS]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS, KC_KP_MINUS),
    [COMMA_DOT]     = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
    [DANCE_19]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
    [DANCE_20]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
    [DANCE_21]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
    [DANCE_22]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
    [HEATMAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_heatmap, dance_heatmap_finished, dance_heatmap_reset),
};
