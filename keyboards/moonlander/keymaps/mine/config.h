/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 10

// Default term that needs to elapse before a regular tap is considered a hold action.
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Allows overriding TAPPING_TERM for defined keys. See tapping_term.c
#define TAPPING_TERM_PER_KEY

// Imortant for home row mods. Else keyboard shortcuts will be accidentally 
// activated when rolling keys during typing.
#define IGNORE_MOD_TAP_INTERRUPT

// Number of taps required to permanently activate a layer using TT()
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"mine_tuning"
#define RGB_MATRIX_STARTUP_SPD 60

// Enable unicode support for windows using WinCompose tool. 
// See X() and XP() in keymap.c and unicodemap.h
#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_F20

// Required to make media keys work with tap_code().
#define TAP_CODE_DELAY 10