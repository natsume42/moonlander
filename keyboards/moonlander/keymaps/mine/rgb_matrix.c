#include "layers.h"
#include QMK_KEYBOARD_H
#include "rgb_animations.h"
#include "leds.h"

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

/* These positions need to be aligned with keymaps. */
#define NUM_LOCK_KEY_INDEX 56
#define GLOBAL_ANIMATION_TOGGLE_INDEX 45
#define MEDIA_L_ANIMATION_TOGGLE_INDEX 27
#define MEDIA_L_LIGHTS_TOGGLE_INDEX 22

// clang-format off
#define ALOHA      {122, 216, 172}
#define ASSESSIN   {0, 249, 243}   /* Assessin’s Red */
#define BARB_L     {30,239,161}    /* Barbarian leather, brown */
#define BLACK      {0, 0, 0}
#define BLUE       {170,255,255}   /* Blue */

/* QWERTZ Layer */
#define BTS        {196, 235, 173} /* purple */
#define GOT7       {91, 165, 255}  /* Aghase Green, 5aff72 */

/* NumPad Layer */
#define CERULEAN   {141, 255, 233} /* Cerulean Blue */
#define EXIT_LIGHT_G {73, 196, 189}  /* Exit Light, green, #52BE2A */

#define CYBER_Y    {35, 255, 255}  /* Cyber Yellow */
#define DELFT_BLUE {180, 255, 233}
#define FUEGO_N    {14, 222, 242}  /* Fuego Nuevo */

/* Mine Layer */
#define FOREST_R   {85,255,105}    /* Forest Ride, green, #006900*/
#define MERLOT     {234,255, 105}  /* Merlot, #690034, accent 1 */
#define DEEP_V     {191, 255, 105} /* Deep Violet, #340069, accent 2 */

/* Edit layer */
#define PEPPRONI   {17,255,170}    /* warm orange */
#define EXTRA_A    {166, 255, 170} /* Extravehicular Activity */
#define DARK_C     {123, 255,84}   /* "White Color", Dark Cyan, #0a9 */
#define CANDY_G    {70, 255, 171}  /* Candy Grass, #3baa00 */


#define FORSYTHIA  {33, 255, 255}  /* orange */
#define GOLD_F     {29, 255, 255}  /* Gold Fusion */
#define GREEN      {86, 255, 255}
#define LINDERH_G  {85, 203, 158}  /* Linderhof Garden, green */
#define MYOGA_P    {233, 218, 217} /* Myoga Purple */
#define RED        {0, 255, 255}
#define RED_VIT    {0, 205, 155}   /* Red Vitality */
#define WHITE      {0, 0, 255}

/* leds are arranged by column:
 * 1. left hand, from left to right
 * 2. left thumb (top to down, big red one)
 * 3. right hand, from right to left
 * 4. right thumb (top to down, big red one)
 */
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [mineL] = { FOREST_R, FOREST_R, MERLOT,   FOREST_R, FOREST_R,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, FOREST_R,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, FOREST_R,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, ALOHA,
                FOREST_R, FOREST_R, DEEP_V,   FOREST_R, PEPPRONI,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R,
                FOREST_R, WHITE,    BTS,

                FOREST_R, FOREST_R, FOREST_R, FOREST_R,

                FOREST_R, FOREST_R, FOREST_R, FOREST_R, CYBER_Y,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, BARB_L,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, FOREST_R,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R, CERULEAN,
                FOREST_R, FOREST_R, DEEP_V,   FOREST_R, GREEN,
                FOREST_R, FOREST_R, FOREST_R, FOREST_R,
                FOREST_R, MERLOT, FOREST_R,

                FOREST_R, FOREST_R, FOREST_R, FOREST_R },

    [ja1L] = {WHITE, WHITE, DELFT_BLUE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, ALOHA,
              WHITE, WHITE, WHITE, WHITE, CERULEAN,
              WHITE, WHITE, WHITE, WHITE,
              FOREST_R, WHITE,    BTS,

              ASSESSIN, WHITE, WHITE, DELFT_BLUE,

              WHITE, WHITE, WHITE, WHITE, CYBER_Y,
              WHITE, WHITE, WHITE, WHITE, BARB_L,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, CERULEAN,
              WHITE, WHITE, WHITE, WHITE, CERULEAN,
              WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE,

              DELFT_BLUE, RED, WHITE, DELFT_BLUE},

    [qwertzL] = {BTS, BTS, BTS,        BTS, BTS,
                 BTS, BTS, BTS,        BTS, BTS,
                 BTS, BTS, BTS,        BTS, BTS,
                 BTS, BTS, BTS,        BTS, ALOHA,
                 BTS, BTS, GOT7, BTS, CERULEAN,
                 BTS, BTS, BTS,        BTS,
                 FOREST_R, WHITE, BTS,

                 WHITE, CERULEAN, BTS, BTS,

                 BTS, BTS, BTS,  BTS, CYBER_Y,
                 BTS, BTS, BTS,  BTS, BARB_L,
                 BTS, BTS, BTS,  BTS, BTS,
                 BTS, BTS, BTS,  BTS, CERULEAN,
                 BTS, BTS, GOT7, BTS, GREEN,
                 BTS, BTS, BTS,  BTS,
                 BTS, GOT7, BTS,

                 BTS, RED, ASSESSIN, BTS},
    [editL] = {BLACK, BLACK,     BLACK,     BLACK,    BLACK,
               BLACK, CANDY_G,   CANDY_G,   BLACK,    BLACK,
               BLACK, PEPPRONI,  EXTRA_A,   BLACK,    BLACK,
               BLACK, EXTRA_A,   EXTRA_A,   BLACK,    BLACK,
               BLACK, PEPPRONI,  EXTRA_A,   BLACK,    BLACK,
               BLACK, CANDY_G,   CANDY_G,   DARK_C,
               FOREST_R, WHITE,  BTS,

               BLACK, BLACK,     BLACK,    BLACK,

               BLACK, BLACK,   BLACK,    BLACK,    BLACK,
               BLACK, BLACK,   BLACK,    BLACK,    BLACK,
               BLACK, CANDY_G, PEPPRONI, PEPPRONI, BLACK,
               BLACK, CANDY_G, PEPPRONI, BLACK,    BLACK,
               BLACK, CANDY_G, PEPPRONI, BLACK,    GREEN,
               BLACK, BLACK,   CANDY_G,  BLACK,
               BLACK, BLACK,   BLACK,

               BLACK, BLACK, BLACK, BLACK},

   [numPadL] = {BLACK, BLACK,   BLACK,   BLACK,      BLACK,
                 BLACK, WHITE,   RED,     LINDERH_G,  BLACK,
                 BLACK, RED_VIT, CYBER_Y, BLACK,      BLACK,
                 BLACK, CYBER_Y, CYBER_Y, DELFT_BLUE, BLACK,
                 BLACK, RED_VIT, CYBER_Y, MYOGA_P,    BLACK,
                 BLACK, BLACK,   BLACK,   FUEGO_N,
                 FOREST_R, WHITE,  BTS,

                 BLACK, BLACK, BLACK, BLACK,

                 BLACK,   CYBER_Y,  CYBER_Y,  BLACK,    BLACK,
                 BLACK,   CYBER_Y,  CYBER_Y,  CYBER_Y,  BLACK,
                 BLACK,   CERULEAN, CERULEAN, CERULEAN, BLACK,
                 BLACK,   CERULEAN, CERULEAN, CERULEAN, WHITE,
                 BLACK,   CERULEAN, CERULEAN, CERULEAN, GREEN,
                 BLACK, CYBER_Y,  CYBER_Y, CERULEAN,
                 BLACK, BLACK,    BLACK,

                 BLACK, BLACK, BLACK, BLACK},

    [prgSymL] = {ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, GOLD_F,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA,
                 FOREST_R, WHITE, BTS,

                 ALOHA, ALOHA, ALOHA, ALOHA,

                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, GREEN,
                 ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA,

                 ALOHA, ALOHA, ALOHA, ALOHA},

    [txtSymL] = {GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, WHITE,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 FOREST_R, WHITE, BTS,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GREEN,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F},

    [ja2L] = {ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              FOREST_R, WHITE,    BTS,

              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,

              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, GREEN,
              ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN,

              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN},

    [fncKeysL] = {BLACK, BLACK,    BLACK,    BLACK, BLACK,
                  BLACK, BLACK,    CERULEAN, BLACK, BLACK,
                  BLACK, CERULEAN, CERULEAN, BLACK, BLACK,
                  BLACK, CERULEAN, CERULEAN, BLACK, GREEN,
                  BLACK, CERULEAN, CERULEAN, BLACK, BLACK,
                  BLACK, CERULEAN, CERULEAN, BLACK,
                  FOREST_R, WHITE, BTS,

                  BLACK, BLACK, BLACK, BLACK,

                  BLACK, BLACK, BLACK, BLACK, BLACK,
                  BLACK, BLACK, BLACK, BLACK, BLACK,
                  BLACK, WHITE, WHITE, WHITE, BLACK,
                  BLACK, WHITE, WHITE, WHITE, BLACK,
                  BLACK, WHITE, WHITE, WHITE, GREEN,
                  BLACK, WHITE, WHITE, WHITE,
                  BLACK, BLACK, BLACK,

                  BLACK, BLACK, BLACK, BLACK},

    [mediaL] = {BLACK, BLACK,    BLACK,   BLACK,     BLACK,
                BLACK, WHITE,    WHITE,   BLACK,     BLACK,
                BLACK, RED_VIT,  RED_VIT, WHITE,     BLACK,
                BLACK, RED_VIT,  RED_VIT, FORSYTHIA, BLACK,
                BLACK, CERULEAN, WHITE,   FORSYTHIA, BLACK,
                BLACK, BLACK,    RED,     BLACK,
                FOREST_R, WHITE, BTS,

                BLACK, BLACK, BLACK, BLACK,

                CERULEAN, WHITE,     BLACK,   BLACK, BLACK,
                BLACK,    BLACK,     BLACK,   BLACK, BLACK,
                BLACK,    WHITE,     CYBER_Y, BLACK, BLACK,
                BLACK,    MYOGA_P,   GREEN,   BLACK, BLACK,
                BLACK,    CERULEAN,  CYBER_Y, BLACK, GREEN,
                BLACK,    BLACK,     BLACK,   BLACK,
                RED,      LINDERH_G, BLACK,

                BLACK, BLACK, BLACK, BLACK},
};
// clang-format on
// void rgb_matrix_set_hsv(int led_pos, uint8_t hue, uint8_t sat, uint8_t val) {
void rgb_matrix_set_hsv(int led_pos, HSV hsv) {
    // HSV   hsv = {.h = hue, .s = sat, .v = val};
    RGB   rgb = hsv_to_rgb(hsv);
    float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(led_pos, f * rgb.r, f * rgb.g, f * rgb.b);
}

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
            rgb_matrix_set_hsv(i, hsv);
        }
    }
}

uint32_t remove_common_layer(uint32_t layer_mask) { return layer_mask & ~(1UL << commonL); }

custom_layers_t get_custom_layer(uint32_t layer_mask) { return (custom_layers_t)biton32(remove_common_layer(layer_state)); }

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
    }

    HSV animationToggleColor = {0, 255, 255};
    animationToggleColor     = rgb_step_rainbow(animationToggleColor, 10, 1);

    switch (get_custom_layer(layer_state)) {
        case mineL:
            set_layer_color(mineL);
            break;
        case ja1L:
            set_layer_color(ja1L);
            break;
        case ja2L:
            set_layer_color(ja2L);
            break;
        case qwertzL:
            set_layer_color(qwertzL);
            break;
        case editL:
            set_layer_color(editL);
            break;
        case numPadL:
            set_layer_color(numPadL);

            if (!get_num_lock()) {
                HSV numLockOffColor = {HSV_RED};
                rgb_matrix_set_hsv(NUM_LOCK_KEY_INDEX, rgb_step_breathe(numLockOffColor, 10, 5));
            } else {
                HSV numLockOnColor = EXIT_LIGHT_G;
                rgb_matrix_set_hsv(NUM_LOCK_KEY_INDEX, numLockOnColor);
            }
            break;
        case prgSymL:
            set_layer_color(prgSymL);
            break;
        case txtSymL:
            set_layer_color(txtSymL);
            break;
        case fncKeysL:
            set_layer_color(fncKeysL);
            break;
        case mediaL:
            set_layer_color(mediaL);
            rgb_matrix_set_hsv(MEDIA_L_ANIMATION_TOGGLE_INDEX, animationToggleColor);
            HSV lightToggleColor = {HSV_WHITE};
            rgb_matrix_set_hsv(MEDIA_L_LIGHTS_TOGGLE_INDEX, rgb_step_breathe(lightToggleColor, 10, 5));
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    rgb_matrix_set_hsv(GLOBAL_ANIMATION_TOGGLE_INDEX, animationToggleColor);
}
