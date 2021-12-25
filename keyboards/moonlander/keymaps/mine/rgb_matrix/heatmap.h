#pragma once
#include QMK_KEYBOARD_H

void heatmap_toggle(void);
void heatmap_reset(void);
void heatmap_dump(void);
void heatmap_process(keypos_t key);
bool heatmap_render(void);
