#undef UNICODEMAP_ENABLE
#define UNICODEMAP_ENABLE
#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"
#include "keyboards/moonlander/config.h"
#include "keyboards/moonlander/moonlander.h"
#include "process_tap_dance.h"
#include "quantum_keycodes.h"

#include "layers.h"
#include "layouts.h"
#include "tapdances.h"
#include "custom_actions/custom_actions.h"
#include "rgb_matrix/heatmap.h"
#include "unicodemap.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    TO_DFLTL = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [commonL] = LAYOUT_moonlander(
    TD(ESC_F4),     _______,        _______,        _______,        _______,        _______,        KC_F9,                                          _______,          _______,        _______,        _______,        _______,        _______,        _______,
    KC_TAB,         _______,        _______,        _______,        _______,        _______,        KC_F21,                                         _______,          _______,        _______,        _______,        _______,        _______,        _______,
    KC_BSPACE,      _______,        _______,        _______,        _______,        _______,        KC_F22,                                         _______,          _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                          _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        MOSL(prgSymL),  TT(editL),                      _______,                                        _______,                          KC_MEH,         KC_LALT,        _______,        _______,        TO(mediaL),
                                                                    OSM(MOD_LSFT), KC_ENTER,        _______,                                        _______,          _______,        LCTL_T(KC_SPACE)
  ),
 [mineL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,          _______,        _______,        _______,        _______,        _______,        _______,
    _______,           KC_W,           KC_L,          KC_U,           KC_A,     TD(MIKE_Q),         _______,                                        _______,       TD(JISX_J),           KC_B,     TD(MINE_D),           KC_G,           DE_Y,          DE_SS,
    _______,           KC_C,   LCTL_T(KC_R),  LGUI_T(KC_I),   LALT_T(KC_E),           KC_O,         _______,                                        _______,             KC_M,   LCTL_T(KC_N),   LGUI_T(KC_T),   LALT_T(KC_S),           KC_H,           DE_Z,
    _______,           KC_V,           KC_X,         DE_UE,          DE_AE,          DE_OE,                                                                              KC_P,           KC_F,       KC_COMMA,         KC_DOT,           KC_K,        _______,
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                          _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,       _______,                                         _______,          _______,        _______
  ),
  [ja1L] = LAYOUT_moonlander(
    _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        _______,                                        _______,        KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_KP_MINUS,
    _______,        KC_C,           JP_COLN,        KC_P,           KC_W,           LSFT(KC_9),     _______,                                        _______,        KC_Z,           KC_Y,           TD(MINE_NO),    LSFT(KC_0),     KC_L,           KC_A,
    _______,        TD(JP_COPY),    KC_T,           KC_D,           KC_S,           KC_Q,           _______,                                        _______,        KC_H,           KC_4,           KC_E,           KC_LBRACKET,    KC_G,           TD(JP_UNDO),
    _______,        TD(JP_PASTE),   TD(JP_CUT),     KC_I,           KC_X,           KC_3,                                                                           LSFT(KC_Z),     KC_DOT,         LSFT(KC_COMMA), LSFT(KC_DOT),   KC_SCOLON,      _______,
    _______,        _______,        _______,        JP_KANA,        _______,                        _______,                                        _______,                        _______,         JP_MHEN,       _______,        _______,        _______,
                                                                    MOSL(ja2L),     _______,        _______,                                        _______,        _______,        JP_HENK
  ),
  [editL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,     _______,        _______,
    _______,        KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      _______,                                        _______,        TD(TAB_EQ),     TD(UNDO_7),     TD(REDO_8),     TD(ALL_9),   DE_MINS,        X(COLON),
    _______,        LGUI_T(KC_HOME),KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         _______,                                        _______,        TD(MULT_DIV),   LCTL_T(KC_4),   LGUI_T(KC_5),   LALT_T(KC_6),TD(PLUS_MINUS), KC_ENTER,
    _______,        LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),     TD(PASTE),      MOSL(fncKeysL),                                                                 KC_0,           KC_1,           KC_2,           KC_3,        TD(COMMA_DOT),  _______,
    _______,        _______,        _______,        _______,        XXXXXXX,                        _______,                                        _______,                        TO_DFLTL,       KC_F20,         _______,     _______,        _______,
                                                                    KC_LSHIFT,      _______,        _______,                                        _______,        _______,        _______
  ),
  [prgSymL] = LAYOUT_moonlander(
    X(CIRC),        X(SUB1),        X(SUB2),        X(SUB3),        X(SUB4),        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        _______,                                        _______,        DE_EXLM,        XP(LT, LE),     XP(GT, GE),     XP(EQ, ALEQ),   DE_AMPR,        X(LONGS),
    _______,        DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        _______,                                        _______,        DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,
    _______,        DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        X(GRAVE),                                                                       XP(PLUS, PLMNS),DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        _______,
    _______,        _______,        _______,        MOSL(txtSymL),  _______,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                                        _______,        _______,        X(NBS)
  ),
  [txtSymL] = LAYOUT_moonlander(
    DE_CIRC,        X(SUP1),        X(SUP2),        X(SUP3),        X(SUP4),        _______,        _______,                                        _______,        _______,        _______,        X(CARON),       X(CEDILLA),     X(MACRON),      DE_ACUT,
    _______,        X(HELLP),       X(EMPTY_SET),   X(SGR),         X(SGL),         DE_PARA,        _______,                                        _______,        DE_EXLM,        X(SLWQM),       X(SLQM),        X(SRQM),        X(EM_DASH),     X(CSHS),
    _______,        X(POUND),       X(EUR),         X(DGR),         X(DGL),         DE_RING,        _______,                                        _______,        DE_QST,         X(DLWQM),       X(DLQM),        X(DRQM),        X(EN_DASH),     _______,
    _______,        X(CENT),        X(DOLLAR),      XP(ARRL,DARRL), XP(ARRR, DARRR),XP(ARRLR, DARRLR),                                                              X(WCIRCLE),     X(CHCKM),       X(XSIGN),       XP(BULLET,MDOT),DE_MINS,        _______,
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                                        _______,        _______,        X(NNBS)
  ),
  [ja2L] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        LSFT(KC_3),     DE_PLUS,        JP_MINS,        KC_2,           KC_SLASH,       _______,                                        _______,        KC_V,           KC_5,           KC_N,           KC_7,           KC_1,           JP_LCBR,
    _______,        LSFT(KC_E),     DE_ACUT,        KC_O,           LSFT(KC_8),     KC_9,           _______,                                        _______,        KC_J,           KC_6,           KC_M,           KC_0,           KC_8,           JP_RCBR,
    _______,        LSFT(KC_4),     LSFT(KC_5),     LSFT(KC_6),     JP_COMM,        LSFT(KC_7),                                                                     KC_BSLASH,      JP_UNDS,        LSFT(DE_MINS),  KC_INT3,        KC_SPACE,       _______,
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        _______,        _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
  ),
  [fncKeysL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        CD(KC_F12),     CD(KC_F7),      CD(KC_F8),      CD(KC_F9),      _______,        _______,
    _______,        _______,        KC_LCTRL,       KC_LGUI,        KC_LALT,        _______,        _______,                                        _______,        CD(KC_F11),     CD(KC_F4),      CD(KC_F5),      CD(KC_F6),      _______,        _______,
    _______,        _______,        _______,        _______,        _______,        TO(fncKeysL),                                                                   CD(KC_F10),     CD(KC_F1),      CD(KC_F2),      CD(KC_F3),      _______,        _______,
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
  ),
  [mediaL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,             _______,             _______,        KC_SYSTEM_SLEEP,
    _______,        RGB_HUI,        RGB_SAI,        RGB_VAI,        RGB_MOD,    TD(HEATMAP_DANCE),  _______,                                        _______,        _______,   KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,     _______,        KC_SYSTEM_POWER,
    _______,        RGB_HUD,        RGB_SAD,        RGB_VAD,        RGB_TOG,    TOGGLE_LAYER_COLOR, _______,                                        _______,        _______,   KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______,        RESET,
    _______,        _______,        AU_TOG,         MU_TOG,         MU_MOD,         KC_INSERT,                                                                   KC_NUMLOCK,        _______,        _______,             _______,             _______,        _______,
    _______,        _______,        _______,        _______,        TO(editL),                      _______,                                        _______,                        TO_DFLTL,       _______,             _______,             _______,        _______,
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
  ),
};
// clang-format on

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    switch_to_mine();

#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        heatmap_process(record->event.key);
    }

    switch (process_custom_action(keycode, record)) {
        case processed:
            return true;
            break;
        case consumed:
            return false;
            break;
        case not_processed:
            break;
    }

    switch (keycode) {
        case TO_DFLTL:
            default_layer_move();
            return false;
            break;
    }
    return true;
}
