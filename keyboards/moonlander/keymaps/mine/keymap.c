#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_jp.h"
#include "keymap_us_international.h"

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
    RGB_SLD = TN_SAFE_RANGE,
    SWITCH_MINE,
    SWITCH_JISX6004,
    SWITCH_QWERTZ,
    TO_DFLTL,
    DE_LSPO,
    DE_RSPC,
    JP_LSPO,
    JP_RSPC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [commonL] = LAYOUT_moonlander(
    TD(ESC_F4),     TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    SWITCH_MINE,                                    TD(HEATMAP_DANCE),          TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_10),   _______,        
    KC_TAB,         _______,        _______,        _______,        _______,        _______,        SWITCH_JISX6004,                                LGUI(LSFT(KC_A)), _______,        _______,        _______,        _______,        _______,        _______,          
    TT(numPadL),    _______,        _______,        _______,        _______,        _______,        SWITCH_QWERTZ,                                  _______,          _______,        _______,        _______,        _______,        _______,        _______,           
    KC_LSHIFT,      _______,        _______,        _______,        _______,        _______,                                                                          _______,        _______,        _______,        _______,        _______,        KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,        KC_LALT,        MOSL(prgSymL),  TT(editL),                      _______,                                        _______,                          KC_MEH,         _______,        TO(editL),  TOGGLE_LAYER_COLOR, TO(mediaL),          
                                                                    OSM(MOD_LSFT),  KC_ENTER,       _______,                                        _______,          KC_BSPACE,      KC_SPACE
  ),
 [mineL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,          _______,        _______,        _______,        _______,        _______,        _______,
    _______,        CD(KC_W),       CD(KC_L),       CD(KC_U),       CD(KC_A),       CD(KC_Q),       _______,                                        _______,          CD(KC_J),       CD(KC_B),       CD(KC_D),       CD(KC_G),       CD(DE_Y),       DE_SS,          
    _______,        CD(KC_C),       CD(KC_R),       CD(KC_I),       CD(KC_E),       CD(KC_O),       _______,                                        LGUI(KC_6),       CD(KC_M),       CD(KC_N),       CD(KC_T),       CD(KC_S),       CD(KC_H),       CD(DE_Z),           
    _______,        CD(KC_V),       CD(KC_X),       DE_UE,          DE_AE,          DE_OE,                                                                            CD(KC_P),       CD(KC_F),       KC_COMMA,       KC_DOT,         CD(KC_K),       _______,      
    _______,        _______,        _______,        _______,        _______,                        LGUI(KC_2),                                     LGUI(KC_3),                       _______,        _______,        _______,        _______,        TO(mediaL),          
                                                                    _______,        KC_ENTER,       _______,                                        CD(KC_DELETE),    _______,        _______
  ),
  [ja1L] = LAYOUT_moonlander(
    _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        _______,                                        _______,        KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_KP_MINUS,    
    _______,        KC_C,           JP_COLN,        KC_P,           KC_W,           LSFT(KC_9),     _______,                                        _______,        KC_Z,           KC_Y,           KC_K,           LSFT(KC_0),     KC_L,           KC_A,           
    _______,        TD(DANCE_19),   KC_T,   KC_D,           KC_S,           KC_Q,           _______,                                        LGUI(KC_6),     KC_H,           KC_4,           KC_E,           KC_LBRACKET,    KC_G,           TD(DANCE_22),   
    _______,        TD(DANCE_20),   TD(DANCE_21),   KC_I,           KC_X,           KC_3,                                                                           LSFT(KC_Z),     KC_DOT,         LSFT(KC_COMMA), LSFT(KC_DOT),   KC_SCOLON,      _______,        
    _______,        _______,        _______,        _______,        _______,                        JP_KANA,                                        JP_MHEN,                        _______,         _______,       _______,        _______,        _______,        
                                                                    MOSL(ja2L),     _______,        _______,                                        _______,        _______,        JP_HENK
  ),
  [qwertzL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        DE_SS,          
    _______,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           _______,                                        _______,        DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           DE_UE,          
    _______,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           _______,                                        _______,        KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          DE_AE,
    _______,        DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         DE_MINS,        _______,      
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        _______,         _______,        _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
  ),
  [editL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        KC_PGUP,        KC_BSPACE,      KC_UP,          KC_DELETE,      KC_PGDOWN,      _______,                                        _______,        _______,        LCTL(KC_X),     LCTL(KC_C),     TD(PASTE),      LCTL(DE_Z),     LCTL(DE_Y),
    _______,        KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         _______,                                        _______,        LCTL(KC_A),     KC_LCTRL,       KC_LGUI,        KC_LALT,        _______,        _______,        
    _______,        _______,        _______,        _______,        MOSL(fncKeysL), KC_INSERT,                                                                      _______,        LCTL(KC_S),     _______,        KC_F20,         _______,         _______,        
    _______,        _______,        _______,        _______,        XXXXXXX,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,        
                                                                    KC_LSHIFT,      _______,        _______,                                        _______,        _______,        _______
  ),
  [numPadL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        KC_NUMLOCK,     _______,        _______,     _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        TD(TAB_EQ),     KC_7,           KC_8,           KC_9,        KC_KP_MINUS,   X(COLON),        
    _______,        _______,        KC_LCTRL,       KC_LGUI,        KC_LALT,        _______,        _______,                                        _______,        TD(MULT_DIV),   KC_4,           KC_5,           KC_6,        TD(PLUS_MINUS), CD(KC_ENTER),   
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        KC_0,           KC_1,           KC_2,           KC_3,        TD(COMMA_DOT),  _______,        
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        TO_DFLTL,       TO(fncKeysL),   _______,     KC_DOT,        _______,        
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______    
  ),
  [prgSymL] = LAYOUT_moonlander(
    X(CIRC),        X(SUB1),        X(SUB2),        X(SUB3),        X(SUB4),        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,        _______,                                        _______,        DE_EXLM,        XP(LT, LE),     XP(GT, GE),     XP(EQ, ALEQ),   DE_AMPR,        X(LONGS),     
    _______,        DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,        _______,                                        _______,        DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        DE_AT,          
    _______,        DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        X(GRAVE),                                                                       XP(PLUS, PLMNS),DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        _______,        
    _______,        _______,        _______,        MOSL(txtSymL),  _______,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
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
    _______,        _______,        _______,        _______,        TO(fncKeysL),   _______,                                                                        CD(KC_F10),     CD(KC_F1),      CD(KC_F2),      CD(KC_F3),      _______,        _______,        
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        TO_DFLTL,       _______,        _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                                        _______,        _______,        _______
  ),
  [mediaL] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,             _______,             _______,        KC_SYSTEM_SLEEP,
    _______,        RGB_HUI,        RGB_SAI,        RGB_VAI,        RGB_MOD,        _______,        _______,                                        _______,        _______,   KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,     _______,        KC_SYSTEM_POWER,
    _______,        RGB_HUD,        RGB_SAD,        RGB_VAD,        RGB_TOG,    TOGGLE_LAYER_COLOR, _______,                                        _______,        _______,   KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______,        RESET,        
    _______,        _______,        AU_TOG,         MU_TOG,         MU_MOD,         _______,                                                                        _______,        _______,        _______,             _______,             _______,        _______,        
    _______,        _______,        _______,        _______,        _______,                        _______,                                        _______,                        TO_DFLTL,       _______,             _______,             _______,        _______,        
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
            break;
        case SWITCH_MINE:
            if (record->event.pressed) {
                switch_to_mine();
            }
            break;
        case SWITCH_JISX6004:
            if (record->event.pressed) {
                switch_to_jisx6004();
            }
            break;
        case SWITCH_QWERTZ:
            if (record->event.pressed) {
                switch_to_qwertz();
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
