#include QMK_KEYBOARD_H

/** \brief Change input language and keyboard layer to Japanese input.
 *
 * ALT+Shift+2 to switch to Japanese IME
 * INT2 (Hiragana key on Japanese keyboard) to switch to Hiragana
 * Switch to JISX6004 layer.
 */
void switch_to_jisx6004(void);

/** \brief Change input language and keyboard layer to German input.
 *
 * ALT+Shift+1 to switch to Japanese IME
 * Switch to Mine layer.
 */
void switch_to_mine(void);
