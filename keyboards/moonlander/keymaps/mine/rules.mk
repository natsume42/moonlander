# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
TAP_DANCE_ENABLE = yes
SRC = matrix.c oneshot.c custom_actions.c layouts.c tapdances.c rgb_matrix.c leds.c
