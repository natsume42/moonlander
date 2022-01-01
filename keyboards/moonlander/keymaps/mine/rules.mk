# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
TAP_DANCE_ENABLE = yes
UNICODEMAP_ENABLE = yes
SRC = matrix.c layouts.c tapdances.c tapping_term.c \
      custom_actions/oneshot.c custom_actions/custom_actions.c custom_actions/ctrl_dance.c \
	  custom_actions/fast_layer_tap.c \
	  rgb_matrix/rgb_matrix.c rgb_matrix/leds.c rgb_matrix/rgb_animations.c \
	  rgb_matrix/heatmap.c rgb_matrix/rgb_matrix_utils.c \
