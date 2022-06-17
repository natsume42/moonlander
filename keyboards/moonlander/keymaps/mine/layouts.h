#pragma once
#include QMK_KEYBOARD_H

/** \brief Change input language to Japanese and keyboard layer to JISX6004.
 *
 * Uses ALT+Shift+2 to switch to Japanese IME
 * Uses INT2 (Hiragana key on Japanese keyboard) to switch to Hiragana
 */
void switch_to_jisx6004(void);

/** \brief Change input language to German and keyboard layer to Mine.
 *
 * Uses ALT+Shift+1 to switch to German IME
 */
void switch_to_mine(void);

/** \brief move to current default layer. */
void default_layer_move(void);
