#include "tapdances.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

#include "rgb_matrix/heatmap.h"
#include "layouts.h"

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

void on_dance_comma_dot_colon(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_COMM);
        tap_code16(DE_COMM);
        tap_code16(DE_COMM);
    }
    if (state->count > 3) {
        tap_code16(DE_COMM);
    }
}

void dance_comma_dot_colon_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[COMMA_DOT].step = dance_step(state);
    switch (dance_state[COMMA_DOT].step) {
        case SINGLE_TAP:
            register_code16(DE_COMM);
            break;
        case DOUBLE_TAP:
            register_code16(DE_COLN);
            break;
        case SINGLE_HOLD:
            register_code16(DE_DOT);
            break;
    }
}

void dance_comma_dot_colon_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[COMMA_DOT].step) {
        case SINGLE_TAP:
            unregister_code16(DE_COMM);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_COLN);
            break;
        case SINGLE_HOLD:
            unregister_code16(DE_DOT);
            break;
    }
    dance_state[COMMA_DOT].step = 0;
}

#define HOLD_DANCE_IMPL(name, tapKey, holdActionFinished, holdActionReset) \
    void on_dance_ ## name (qk_tap_dance_state_t *state, void *user_data) { \
        if (state->count == 3) { \
            tap_code16(tapKey); \
            tap_code16(tapKey); \
            tap_code16(tapKey); \
        } \
        if (state->count > 3) { \
            tap_code16(tapKey); \
        } \
    } \
\
    void dance_ ## name ## _finished(qk_tap_dance_state_t *state, void *user_data) { \
        dance_state[name].step = dance_step(state); \
        switch (dance_state[name].step) { \
            case SINGLE_TAP: \
                register_code16(tapKey); \
                break; \
            case DOUBLE_TAP: \
                register_code16(tapKey); \
                register_code16(tapKey); \
                break; \
            case SINGLE_HOLD: \
                holdActionFinished; \
                break; \
        } \
    } \
\
    void dance_ ## name ## _reset(qk_tap_dance_state_t *state, void *user_data) { \
        wait_ms(10); \
        switch (dance_state[name].step) { \
            case SINGLE_TAP: \
                unregister_code16(tapKey); \
                break; \
            case DOUBLE_TAP: \
                unregister_code16(tapKey); \
                unregister_code16(tapKey); \
                break; \
            case SINGLE_HOLD: \
                holdActionReset; \
                break; \
        } \
        dance_state[name].step = 0; \
    } 

#define HOLD_DANCE_KEY(name, tapKey, holdKey) HOLD_DANCE_IMPL(name, tapKey, register_code16(holdKey), unregister_code16(holdKey))

#define HOLD_DANCE(name) ACTION_TAP_DANCE_FN_ADVANCED(on_dance_ ## name, dance_ ## name ## _finished, dance_ ## name ## _reset)

HOLD_DANCE_KEY(JP_COPY, KC_F, LCTL(KC_C))
HOLD_DANCE_KEY(JP_PASTE, KC_R, LCTL(KC_V))
HOLD_DANCE_KEY(JP_CUT, KC_B, LCTL(KC_X))
HOLD_DANCE_KEY(JP_UNDO, KC_U, LCTL(KC_Z))
HOLD_DANCE_KEY(MIKE_M, KC_M, LGUI(LSFT(KC_A)))
HOLD_DANCE_KEY(UNDO_7, KC_7, LCTL(DE_Z))
HOLD_DANCE_KEY(REDO_8, KC_8, LCTL(DE_Y))
HOLD_DANCE_KEY(ALL_9, KC_9, LCTL(KC_A))

HOLD_DANCE_IMPL(MINE_NO, KC_K, , switch_to_mine())
HOLD_DANCE_IMPL(JISX_J, KC_J, , switch_to_jisx6004())

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_F4]        = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc_f4, dance_esc_f4_finished, dance_esc_f4_reset),
    [MULT_DIV]      = ACTION_TAP_DANCE_DOUBLE(DE_ASTR, DE_SLSH),
    [PLUS_MINUS]    = ACTION_TAP_DANCE_DOUBLE(DE_PLUS, DE_MINS),
    [COMMA_DOT]     = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_comma_dot_colon, dance_comma_dot_colon_finished, dance_comma_dot_colon_reset),
    [TAB_EQ]        = ACTION_TAP_DANCE_DOUBLE(KC_TAB, DE_EQL),
    [UNDO_7]        = HOLD_DANCE(UNDO_7),
    [REDO_8]        = HOLD_DANCE(REDO_8),
    [ALL_9]         = HOLD_DANCE(ALL_9),
    [JP_COPY]       = HOLD_DANCE(JP_COPY),
    [JP_PASTE]      = HOLD_DANCE(JP_PASTE),
    [JP_CUT]        = HOLD_DANCE(JP_CUT),
    [JP_UNDO]       = HOLD_DANCE(JP_UNDO),
    [HEATMAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_heatmap, dance_heatmap_finished, dance_heatmap_reset),
    [PASTE]         = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_V),LGUI(KC_V)),
    [MIKE_M]        = HOLD_DANCE(MIKE_M),
    [MINE_NO]       = HOLD_DANCE(MINE_NO),
    [JISX_J]        = HOLD_DANCE(JISX_J),
};
