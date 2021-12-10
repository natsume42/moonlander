#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

#include "layers.h"
#include "languages.h"
#include "oneshot.h"
#include "languages.h"
#include "tapdances.h"
#include "leds.h"

#ifdef CONSOLE_ENABLE
#   include "print.h"
#endif

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3,
    ST_MACRO_4,
    ST_MACRO_5,
    ST_MACRO_6,
    ST_MACRO_7,
    ST_MACRO_8,
    ST_MACRO_9,
    ST_MACRO_10,
    ST_MACRO_11,
    ST_MACRO_12,
    ST_MACRO_13,
    ST_MACRO_14,
    ST_MACRO_15,
    ST_MACRO_16,
    ST_MACRO_17,
    ST_MACRO_18,
    ST_MACRO_19,
    ST_MACRO_20,
    ST_MACRO_21,
    ST_MACRO_22,
    ST_MACRO_23,
    ST_MACRO_24,
    ST_MACRO_25,
    ST_MACRO_26,
    ST_MACRO_27,
    ST_MACRO_28,
    ST_MACRO_29,
    ST_MACRO_30,
    ST_MACRO_31,
    ST_MACRO_32,
    ST_MACRO_33,
    ST_MACRO_34,
    ST_MACRO_35,
    ST_MACRO_36,
    ST_MACRO_37,
    ST_MACRO_38,
    ST_MACRO_39,
    ST_MACRO_40,
    ST_MACRO_41,
    ST_MACRO_42,
    ST_MACRO_43,
    ST_MACRO_44,
    ST_MACRO_45,
    ST_MACRO_46,
    SWITCH_DE,
    SWITCH_JP,
    OSL_prgSym,
    OSL_txtSym,
    OSL_fncKeys,
    DE_LSPO,
    DE_RSPC,
    JP_LSPO,
    JP_RSPC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [mineL] = LAYOUT_moonlander(
    TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    SWITCH_DE,                                     _______,        TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_10),   TD(DANCE_11),   DE_MINS,        
    KC_TAB,         KC_J,           KC_L,           KC_U,           KC_A,           KC_Q,           SWITCH_JP,                                     LGUI(LSFT(KC_A)),KC_W,           KC_B,           KC_D,           KC_G,           DE_Y,           DE_SS,          
    LCTL(KC_BSPACE),KC_C,           KC_R,           KC_I,           KC_E,           KC_O,           TO(5),                                                                          LGUI(KC_6),     KC_M,           KC_N,           KC_T,           KC_S,           KC_H,           DE_Z,           
    KC_LSHIFT,      KC_V,           KC_X,           DE_UE,          DE_AE,          DE_OE,                                          KC_P,           KC_F,           TD(DANCE_12),   TD(DANCE_13),   KC_K,           KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,        KC_LALT,        OSL_prgSym,     TO(editL),          LGUI(KC_2),                                                                                                     LGUI(KC_3),     KC_MEH,         TO(2),          OSL(7),         TO(9),          TO(8),          
    KC_LSHIFT,      TD(DANCE_6),    KC_LCTRL,                       TD(DANCE_14),   KC_BSPACE,      KC_SPACE
  ),
  [editL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      _______,                                        _______,        _______,        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     _______,        _______,        
    _______,        KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         _______,                                                                        _______,        _______,        KC_LCTRL,       KC_LGUI,        KC_LALT,        LCTL(KC_A),     _______,        
    _______,        _______,        LCTL(KC_BSPACE),_______,        RCTL(KC_DELETE),KC_INSERT,                                      _______,        _______,        _______,        KC_RALT,        _______,        _______,        
    _______,        _______,        _______,        _______,        TO(0),          _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    KC_LSHIFT,      _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [numPadL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        KC_NUMLOCK,     _______,        _______,        _______,        _______,        
    _______,        KC_MS_BTN3,     KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  _______,        _______,                                        _______,        KC_TAB,         KC_KP_7,        KC_KP_8,        KC_KP_9,        TD(DANCE_15),   DE_COLN,        
    _______,        KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______,        _______,                                                                        _______,        DE_EQL,         KC_KP_4,        KC_KP_5,        KC_KP_6,        TD(DANCE_16),   TD(DANCE_17),   
    _______,        KC_MS_BTN2,     _______,        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,                                   KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        TD(DANCE_18),   _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [prgSymL] = LAYOUT_moonlander(
    _______,        ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        _______,                                        _______,        DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        ST_MACRO_5,     
    _______,        DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        _______,                                                                        _______,        DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,          
    _______,        DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        _______,        
    _______,        _______,        _______,        OSL_txtSym,     _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [txtSymL] = LAYOUT_moonlander(
    _______,        ST_MACRO_6,     DE_SQ2,         DE_SQ3,         ST_MACRO_7,     _______,        _______,                                        _______,        _______,        _______,        _______,        ST_MACRO_19,    ST_MACRO_20,    DE_ACUT,        
    _______,        ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    DE_PARA,        _______,                                        _______,        DE_EXLM,        ST_MACRO_21,    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    
    _______,        ST_MACRO_12,    DE_EURO,        ST_MACRO_13,    ST_MACRO_14,    DE_RING,        _______,                                                                        _______,        DE_QST,         ST_MACRO_26,    ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    _______,        
    _______,        ST_MACRO_15,    KC_DLR,         ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,                                    ST_MACRO_30,    ST_MACRO_31,    ST_MACRO_32,    ST_MACRO_33,    DE_MINS,        _______,        
    _______,        _______,        _______,        OSL_fncKeys,          _______,        _______,                                                                                                        ST_MACRO_34,    TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        ST_MACRO_35
  ),
  [ja1L] = LAYOUT_moonlander(
    _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        _______,                                        _______,        KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_KP_MINUS,    
    _______,        KC_C,           JP_COLN,        KC_P,           KC_W,           LSFT(KC_9),     _______,                                        _______,        KC_Z,           KC_Y,           KC_K,           LSFT(KC_0),     KC_L,           KC_A,           
    JP_ZHTG,        TD(DANCE_19),   KC_T,           KC_D,           KC_S,           KC_Q,           _______,                                                                        _______,        KC_H,           KC_4,           KC_E,           KC_LBRACKET,    KC_G,           TD(DANCE_22),   
    _______,        TD(DANCE_20),   TD(DANCE_21),   KC_I,           KC_X,           KC_3,                                           LSFT(KC_Z),     KC_DOT,         LSFT(KC_COMMA), LSFT(KC_DOT),   KC_SCOLON,      _______,        
    _______,        _______,        _______,        _______,        _______,        JP_KANA,                                                                                                        JP_MHEN,        TO(0),          _______,        _______,        _______,        _______,        
    OSL(6),         _______,        _______,                        _______,        _______,        JP_HENK
  ),
  [ja2L] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        LSFT(KC_3),     DE_PLUS,        JP_MINS,        KC_2,           KC_SLASH,       _______,                                        _______,        KC_V,           KC_5,           KC_N,           KC_7,           KC_1,           JP_LCBR,        
    _______,        LSFT(KC_E),     DE_ACUT,        KC_O,           LSFT(KC_8),     KC_9,           _______,                                                                        _______,        KC_J,           KC_6,           KC_M,           KC_0,           KC_8,           JP_RCBR,        
    _______,        LSFT(KC_4),     LSFT(KC_5),     LSFT(KC_6),     JP_COMM,        LSFT(KC_7),                                     KC_BSLASH,      JP_UNDS,        LSFT(DE_MINS),  KC_INT3,        KC_SPACE,       _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [fncKeysL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        ST_MACRO_36,    ST_MACRO_37,    ST_MACRO_38,    ST_MACRO_39,    _______,                                        _______,        TD(DANCE_23),   TD(DANCE_24),   TD(DANCE_25),   TD(DANCE_26),   _______,        _______,        
    _______,        ST_MACRO_40,    ST_MACRO_41,    ST_MACRO_42,    ST_MACRO_43,    ST_MACRO_44,    _______,                                                                        _______,        TD(DANCE_27),   TD(DANCE_28),   TD(DANCE_29),   TD(DANCE_30),   _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                        TD(DANCE_31),   TD(DANCE_32),   TD(DANCE_33),   TD(DANCE_34),   _______,        _______,        
    _______,        _______,        _______,        TO(mineL),          _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [mediaL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        RESET,          _______,        _______,        _______,        _______,        _______,        KC_SYSTEM_SLEEP,
    _______,        RGB_VAI,        RGB_HUI,        RGB_SAI,        RGB_MOD,        _______,        _______,                                        WEBUSB_PAIR,    _______,        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  _______,        KC_SYSTEM_POWER,
    _______,        RGB_VAD,        RGB_HUD,        RGB_SAD,        RGB_TOG,        TOGGLE_LAYER_COLOR,_______,                                                                        _______,        _______,        KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,_______,        _______,        
    _______,        _______,        AU_TOG,         MU_TOG,         MU_MOD,         _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [qwertyL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        DE_SS,          
    _______,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           _______,                                        _______,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,          
    _______,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           _______,                                                                        _______,        KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,          
    KC_LSHIFT,      DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           _______,        _______,        DE_MINS,        KC_RSHIFT,      
    _______,        _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        TO(0),          _______,        _______,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
};
// clang-format on


void keyboard_post_init_user(void) {
  rgb_matrix_enable();

#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL_prgSym:
            process_oneshot_key(prgSymL, record);
            break;
        case OSL_txtSym:
            process_oneshot_key(txtSymL, record);
            break;
        case OSL_fncKeys:
            process_oneshot_key(fncKeysL, record);
            break;
        case SWITCH_DE:
            if (record->event.pressed) {
                switch_to_german();
            }
            break;
        case SWITCH_JP:
            if (record->event.pressed) {
                switch_to_japanese();
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_8) SS_TAP(X_1)));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_8) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_8) SS_TAP(X_3)));
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_8) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_7) SS_TAP(X_F)));
            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_5)));
            }
            break;
        case ST_MACRO_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_6)));
            }
            break;
        case ST_MACRO_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_7)));
            }
            break;
        case ST_MACRO_10:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_5)));
            }
            break;
        case ST_MACRO_11:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_3) SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_12:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_6)));
            }
            break;
        case ST_MACRO_13:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_5)));
            }
            break;
        case ST_MACRO_14:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_4)));
            }
            break;
        case ST_MACRO_15:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_9)));
            }
            break;
        case ST_MACRO_16:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_17:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_18:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_9)));
            }
            break;
        case ST_MACRO_19:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_0) SS_TAP(X_3) SS_TAP(X_2) SS_TAP(X_7)));
            }
            break;
        case ST_MACRO_20:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_0) SS_TAP(X_3) SS_TAP(X_0) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_21:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_0)));
            }
            break;
        case ST_MACRO_22:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_8)));
            }
            break;
        case ST_MACRO_23:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_24:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_25:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_1) SS_TAP(X_E) SS_TAP(X_9) SS_TAP(X_E)));
            }
            break;
        case ST_MACRO_26:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2)));
            }
            break;
        case ST_MACRO_27:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7)));
            }
            break;
        case ST_MACRO_28:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
            }
            break;
        case ST_MACRO_29:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_3)));
            }
            break;
        case ST_MACRO_30:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_9)));
            }
            break;
        case ST_MACRO_31:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_7) SS_TAP(X_1) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_32:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_5)));
            }
            break;
        case ST_MACRO_33:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_34:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_F)));
            }
            break;
        case ST_MACRO_35:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_36:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_5)));
            }
            break;
        case ST_MACRO_37:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_6) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_38:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_6) SS_TAP(X_5)));
            }
            break;
        case ST_MACRO_39:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_1)));
            }
            break;
        case ST_MACRO_40:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_0)));
            }
            break;
        case ST_MACRO_41:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_4) SS_TAP(X_8)));
            }
            break;
        case ST_MACRO_42:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_D) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_43:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_D) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_44:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_D) SS_TAP(X_4)));
            }
            break;
        case ST_MACRO_45:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_3)));
            }
            break;
        case ST_MACRO_46:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_2)));
            }
            break;
        case DE_LSPO:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
            return false;
        case DE_RSPC:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
            return false;
        case JP_LSPO:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
            return false;
        case JP_RSPC:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
