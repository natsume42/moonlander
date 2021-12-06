#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "customlogic.h"

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
    OSL3,
    DE_LSPO,
    DE_RSPC,
    JP_LSPO,
    JP_RSPC,
};

enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
    DANCE_2,
    DANCE_3,
    DANCE_4,
    DANCE_5,
    DANCE_6,
    DANCE_7,
    DANCE_8,
    DANCE_9,
    DANCE_10,
    DANCE_11,
    DANCE_12,
    DANCE_13,
    DANCE_14,
    DANCE_15,
    DANCE_16,
    DANCE_17,
    DANCE_18,
    DANCE_19,
    DANCE_20,
    DANCE_21,
    DANCE_22,
    DANCE_23,
    DANCE_24,
    DANCE_25,
    DANCE_26,
    DANCE_27,
    DANCE_28,
    DANCE_29,
    DANCE_30,
    DANCE_31,
    DANCE_32,
    DANCE_33,
    DANCE_34,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0]  = LAYOUT_moonlander(TD(DANCE_0), TD(DANCE_1), TD(DANCE_2), TD(DANCE_3), TD(DANCE_4), TD(DANCE_5), SWITCH_DE, KC_TRANSPARENT, TD(DANCE_7), TD(DANCE_8), TD(DANCE_9), TD(DANCE_10), TD(DANCE_11), DE_MINS, KC_TAB, KC_J, KC_L, KC_U, KC_A, KC_Q, SWITCH_JP, LGUI(LSFT(KC_A)), KC_W, KC_B, KC_D, KC_G, DE_Y, DE_SS, LCTL(KC_BSPACE), KC_C, KC_R, KC_I, KC_E, KC_O, TO(5), LGUI(KC_6), KC_M, KC_N, KC_T, KC_S, KC_H, DE_Z, KC_LSHIFT, KC_V, KC_X, DE_UE, DE_AE, DE_OE, KC_P, KC_F, TD(DANCE_12), TD(DANCE_13), KC_K, KC_RSHIFT, KC_LCTRL, KC_LGUI, KC_LALT, OSL3, TO(1), LGUI(KC_2), LGUI(KC_3), KC_MEH, TO(2), OSL(7), TO(9), TO(8), KC_LSHIFT, TD(DANCE_6), KC_LCTRL, TD(DANCE_14), KC_BSPACE, KC_SPACE),
    [1]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_BSPACE, KC_UP, KC_DELETE, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL, KC_LGUI, KC_LALT, LCTL(KC_A), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_BSPACE), KC_TRANSPARENT, RCTL(KC_DELETE), KC_INSERT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RALT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT, KC_TRANSPARENT, KC_TRANSPARENT,
                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [2]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NUMLOCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TAB, KC_KP_7, KC_KP_8, KC_KP_9, TD(DANCE_15), DE_COLN, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_EQL, KC_KP_4, KC_KP_5, KC_KP_6, TD(DANCE_16), TD(DANCE_17), KC_TRANSPARENT, KC_MS_BTN2, KC_TRANSPARENT, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, TD(DANCE_18), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                            KC_TRANSPARENT, KC_TRANSPARENT),
    [3]  = LAYOUT_moonlander(KC_TRANSPARENT, ST_MACRO_1, ST_MACRO_2, ST_MACRO_3, ST_MACRO_4, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, KC_TRANSPARENT, KC_TRANSPARENT, DE_EXLM, DE_LESS, DE_MORE, DE_EQL, DE_AMPR, ST_MACRO_5, KC_TRANSPARENT, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, KC_TRANSPARENT, KC_TRANSPARENT, DE_QST, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT, KC_TRANSPARENT, DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV, DE_PLUS, DE_PERC, DE_DQOT, DE_QUOT, DE_SCLN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(4), KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [4]  = LAYOUT_moonlander(KC_TRANSPARENT, ST_MACRO_6, DE_SQ2, DE_SQ3, ST_MACRO_7, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_19, ST_MACRO_20, DE_ACUT, KC_TRANSPARENT, ST_MACRO_8, ST_MACRO_9, ST_MACRO_10, ST_MACRO_11, DE_PARA, KC_TRANSPARENT, KC_TRANSPARENT, DE_EXLM, ST_MACRO_21, ST_MACRO_22, ST_MACRO_23, ST_MACRO_24, ST_MACRO_25, KC_TRANSPARENT, ST_MACRO_12, DE_EURO, ST_MACRO_13, ST_MACRO_14, DE_RING, KC_TRANSPARENT, KC_TRANSPARENT, DE_QST, ST_MACRO_26, ST_MACRO_27, ST_MACRO_28, ST_MACRO_29, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_15, KC_DLR, ST_MACRO_16, ST_MACRO_17, ST_MACRO_18, ST_MACRO_30, ST_MACRO_31, ST_MACRO_32, ST_MACRO_33, DE_MINS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_34, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_35),
    [5]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_MINUS, KC_TRANSPARENT, KC_C, JP_COLN, KC_P, KC_W, LSFT(KC_9), KC_TRANSPARENT, KC_TRANSPARENT, KC_Z, KC_Y, KC_K, LSFT(KC_0), KC_L, KC_A, JP_ZHTG, TD(DANCE_19), KC_T, KC_D, KC_S, KC_Q, KC_TRANSPARENT, KC_TRANSPARENT, KC_H, KC_4, KC_E, KC_LBRACKET, KC_G, TD(DANCE_22), KC_TRANSPARENT, TD(DANCE_20), TD(DANCE_21), KC_I, KC_X, KC_3, LSFT(KC_Z), KC_DOT, LSFT(KC_COMMA), LSFT(KC_DOT), KC_SCOLON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, JP_KANA, JP_MHEN, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(6), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, JP_HENK),
    [6]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_3), DE_PLUS, JP_MINS, KC_2, KC_SLASH, KC_TRANSPARENT, KC_TRANSPARENT, KC_V, KC_5, KC_N, KC_7, KC_1, JP_LCBR, KC_TRANSPARENT, LSFT(KC_E), DE_ACUT, KC_O, LSFT(KC_8), KC_9, KC_TRANSPARENT, KC_TRANSPARENT, KC_J, KC_6, KC_M, KC_0, KC_8, JP_RCBR, KC_TRANSPARENT, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), JP_COMM, LSFT(KC_7), KC_BSLASH, JP_UNDS, LSFT(DE_MINS), KC_INT3, KC_SPACE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [7]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_36, ST_MACRO_37, ST_MACRO_38, ST_MACRO_39, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_23), TD(DANCE_24), TD(DANCE_25), TD(DANCE_26), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_40, ST_MACRO_41, ST_MACRO_42, ST_MACRO_43, ST_MACRO_44, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_27), TD(DANCE_28), TD(DANCE_29), TD(DANCE_30), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_31), TD(DANCE_32), TD(DANCE_33), TD(DANCE_34), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT,
                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [8]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SYSTEM_SLEEP, KC_TRANSPARENT, RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_SYSTEM_POWER, KC_TRANSPARENT, RGB_VAD, RGB_HUD, RGB_SAD, RGB_TOG, TOGGLE_LAYER_COLOR, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, AU_TOG, MU_TOG, MU_MOD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [9]  = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, DE_SS, KC_TRANSPARENT, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRANSPARENT, KC_TRANSPARENT, DE_Z, KC_U, KC_I, KC_O, KC_P, DE_UE, KC_TRANSPARENT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRANSPARENT, KC_TRANSPARENT, KC_H, KC_J, KC_K, KC_L, DE_OE, DE_AE, KC_LSHIFT, DE_Y, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_TRANSPARENT, KC_TRANSPARENT, DE_MINS, KC_RSHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [10] = LAYOUT_moonlander(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_J), LSFT(KC_L), LSFT(KC_U), LSFT(KC_A), LSFT(KC_Q), KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_W), LSFT(KC_B), LSFT(KC_D), LSFT(KC_G), LSFT(DE_Y), DE_SS, KC_TRANSPARENT, LSFT(KC_C), LSFT(KC_R), LSFT(KC_I), LSFT(KC_E), LSFT(KC_O), KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_M), LSFT(KC_N), LSFT(KC_T), LSFT(KC_S), LSFT(KC_H), LSFT(DE_Z), KC_TRANSPARENT, LSFT(KC_V), LSFT(KC_X), LSFT(DE_UE), LSFT(DE_AE), LSFT(DE_OE), LSFT(KC_P), LSFT(KC_F), ST_MACRO_45, ST_MACRO_46, LSFT(KC_K), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
};

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {33, 255, 255}, {33, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {86, 255, 255}, {0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {86, 255, 255}, {86, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {86, 255, 255}, {0, 255, 255}, {86, 255, 255}, {0, 0, 0}, {33, 255, 255}, {33, 255, 255}, {141, 255, 233}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {30, 96, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {30, 96, 255}, {141, 255, 233}, {141, 255, 233}, {0, 0, 0}, {0, 0, 0}, {30, 96, 255}, {141, 255, 233}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {30, 96, 255}, {141, 255, 233}, {0, 0, 0}, {86, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [2] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 255, 255}, {85, 203, 158}, {0, 0, 0}, {0, 0, 0}, {0, 205, 155}, {35, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {35, 255, 255}, {35, 255, 255}, {180, 255, 233}, {0, 0, 0}, {0, 0, 0}, {0, 205, 155}, {35, 255, 255}, {233, 218, 217}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {14, 222, 242}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {35, 255, 255}, {35, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {35, 255, 255}, {35, 255, 255}, {35, 255, 255}, {0, 0, 0}, {0, 0, 0}, {154, 255, 255}, {154, 255, 255}, {154, 255, 255}, {0, 0, 0}, {0, 0, 0}, {154, 255, 255}, {154, 255, 255}, {154, 255, 255}, {0, 0, 0}, {249, 228, 255}, {154, 255, 255}, {154, 255, 255}, {154, 255, 255}, {86, 255, 255}, {0, 0, 0}, {35, 255, 255}, {35, 255, 255}, {154, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [3] = {{122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {29, 255, 255},  {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {29, 255, 255}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172},
           {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {86, 255, 255}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}, {122, 216, 172}},

    [4] = {{29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {86, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255},
           {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {86, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}, {29, 255, 255}},

    [5] = {{0, 0, 255}, {0, 0, 255}, {154, 255, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {154, 255, 255}, {0, 0, 255}, {0, 0, 255}, {154, 255, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {86, 255, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {154, 255, 255}, {0, 0, 255}, {0, 0, 255}, {154, 255, 255}},

    [6] = {{0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243},  {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243},
           {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {86, 255, 255}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}, {0, 249, 243}},

    [7] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {152, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {152, 255, 255}, {152, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {152, 255, 255}, {152, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {152, 255, 255}, {152, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {152, 255, 255}, {152, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {86, 255, 255}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [8] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {249, 228, 255}, {249, 228, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {249, 228, 255}, {249, 228, 255}, {33, 255, 255}, {0, 0, 0}, {0, 0, 0}, {154, 255, 255}, {0, 0, 255}, {33, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {154, 255, 255}, {0, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {35, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {199, 255, 255}, {86, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {141, 255, 233}, {35, 255, 255}, {0, 0, 0}, {86, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {243, 222, 234}, {85, 203, 158}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [9] = {{196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173},
           {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {86, 255, 255},  {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}, {196, 235, 173}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 6:
            set_layer_color(6);
            break;
        case 7:
            set_layer_color(7);
            break;
        case 8:
            set_layer_color(8);
            break;
        case 9:
            set_layer_color(9);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL3:
            if (record->event.pressed) {
                reset_oneshot_layer();
                set_oneshot_layer(3, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
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

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[35];

uint8_t dance_step(qk_tap_dance_state_t *state);

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

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_21(qk_tap_dance_state_t *state, void *user_data);
void dance_21_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_21_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_22(qk_tap_dance_state_t *state, void *user_data);
void dance_22_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_22_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

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
void on_dance_34(qk_tap_dance_state_t *state, void *user_data);
void dance_34_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_34_reset(qk_tap_dance_state_t *state, void *user_data);

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
