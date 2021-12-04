/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 10

#undef TAPPING_TERM
#define TAPPING_TERM 201

#undef IGNORE_MOD_TAP_INTERRUPT

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"DA6AE/0eDpl"
#define RGB_MATRIX_STARTUP_SPD 60
