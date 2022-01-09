#include "tapdances.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

#include "rgb_matrix/heatmap.h"

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };


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

void on_dance_esc_f4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if (state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_esc_f4_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_esc_f4_reset(qk_tap_dance_state_t *state, void *user_data) {
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

void on_win_combo(qk_tap_dance_state_t *state, void *user_data, uint8_t keycode) {
    if (state->count == 3) {
        tap_code16(keycode);
        tap_code16(keycode);
        tap_code16(keycode);
    }
    if (state->count > 3) {
        tap_code16(keycode);
    }
}

void win_combo_finished(qk_tap_dance_state_t *state, void *user_data, int index, uint8_t keycode) {
    dance_state[index].step = dance_step(state);
    switch (dance_state[index].step) {
        case SINGLE_TAP:
            register_code16(keycode);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(keycode));
            break;
        case DOUBLE_TAP:
            register_code16(keycode);
            register_code16(keycode);
            break;
        case DOUBLE_HOLD:
            register_code16(LGUI(keycode));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(keycode);
            register_code16(keycode);
    }
}

void win_combo_reset(qk_tap_dance_state_t *state, void *user_data, int index, uint8_t keycode) {
    wait_ms(10);
    switch (dance_state[index].step) {
        case SINGLE_TAP:
            unregister_code16(keycode);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(keycode));
            break;
        case DOUBLE_TAP:
            unregister_code16(keycode);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LGUI(keycode));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(keycode);
            break;
    }
    dance_state[index].step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_1); }
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_1, KC_1); }
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_1, KC_1); }

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_2); }
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_2, KC_2); }
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_2, KC_2); }

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_3); }
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_3, KC_3); }
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_3, KC_3); }

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_4); }
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_4, KC_4); }
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_4, KC_4); }

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_5); }
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_5, KC_5); }
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_5, KC_5); }

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_6); }
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_6, KC_6); }
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_6, KC_6); }

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_7); }
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_7, KC_7); }
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_7, KC_7); }

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_8); }
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_8, KC_8); }
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_8, KC_8); }

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_9); }
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_9, KC_9); }
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_9, KC_9); }

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) { on_win_combo(state, user_data, KC_0); }
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) { win_combo_finished(state, user_data, DANCE_10, KC_0); }
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) { win_combo_reset(state, user_data, DANCE_10, KC_0); }

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
        case DOUBLE_TAP:
            heatmap_dump();
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
    [ESC_F4]        = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc_f4, dance_esc_f4_finished, dance_esc_f4_reset),
    [DANCE_1]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_4]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [DANCE_5]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [DANCE_6]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [DANCE_7]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [DANCE_8]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [DANCE_9]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    [DANCE_10]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    [MULT_DIV]      = ACTION_TAP_DANCE_DOUBLE(KC_KP_ASTERISK, MULT_DIV),
    [PLUS_MINUS]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS, KC_KP_MINUS),
    [COMMA_DOT]     = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
    [DANCE_19]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
    [DANCE_20]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
    [DANCE_21]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
    [DANCE_22]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
    [HEATMAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_heatmap, dance_heatmap_finished, dance_heatmap_reset),
    [PASTE]         = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_V),LGUI(KC_V)),
};
