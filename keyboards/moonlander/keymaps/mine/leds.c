#include "leds.h"
#include "layers.h"

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

// clang-format off
#define ALOHA      {122, 216, 172}
#define ASSESSIN   {0, 249, 243}   /* Assessin’s Red */
#define BLACK      {0, 0, 0}
#define BTS        {196, 235, 173} /* purple */
#define CERULEAN   {141, 255, 233} /* Cerulean Blue */
#define CYBER_Y    {35, 255, 255}  /* Cyber Yellow */
#define DELFT_BLUE {180, 255, 233}
#define FUEGO_N    {14, 222, 242}  /* Fuego Nuevo */
#define FORSYTHIA  {33, 255, 255}  /* orange */
#define GOLD_F     {29, 255, 255}  /* Gold Fusion */
#define GREEN      {86, 255, 255}
#define LEMON      {30, 96, 255}   /* Lemon Drops, pale yellow */
#define LINDERH_G  {85, 203, 158}  /* Linderhof Garden, green */
#define MYOGA_P    {233, 218, 217} /* Myoga Purple */
#define RED        {0, 255, 255}
#define RED_VIT    {0, 205, 155}   /* Red Vitality */
#define WHITE      {0, 0, 255}

/* leds are arranged by column:
 * 1. left hand, from left to right
 * 2. left thumb
 * 3. right hand, from right to left
 * 4. right thumb.
 */
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [editL] = {BLACK, BLACK,     BLACK,     BLACK,    BLACK,
               BLACK, FORSYTHIA, FORSYTHIA, BLACK,    BLACK,
               BLACK, RED,       GREEN,     RED,      BLACK,
               BLACK, GREEN,     GREEN,     BLACK,    BLACK,
               BLACK, RED,       GREEN,     RED,      GREEN,
               BLACK, FORSYTHIA, FORSYTHIA, CERULEAN,
               BLACK, BLACK,     BLACK,

               BLACK, BLACK,     BLACK,    BLACK,

               BLACK, BLACK,  BLACK,    BLACK,    BLACK,
               BLACK, BLACK,  LEMON,    BLACK,    BLACK,
               BLACK, LEMON,  CERULEAN, CERULEAN, BLACK,
               BLACK, LEMON,  CERULEAN, BLACK,    BLACK,
               BLACK, LEMON,  CERULEAN, BLACK,    GREEN,
               BLACK, BLACK,  BLACK,    BLACK,
               BLACK, BLACK,  BLACK,

               BLACK, BLACK, BLACK, BLACK},

    [numPadL] = {BLACK, BLACK,   BLACK,   BLACK,      BLACK,
                 BLACK, WHITE,   RED,     LINDERH_G,  BLACK,
                 BLACK, RED_VIT, CYBER_Y, BLACK,      BLACK,
                 BLACK, CYBER_Y, CYBER_Y, DELFT_BLUE, BLACK,
                 BLACK, RED_VIT, CYBER_Y, MYOGA_P,    BLACK,
                 BLACK, BLACK,   BLACK,   FUEGO_N,
                 BLACK, BLACK,   BLACK,

                 BLACK, BLACK, BLACK, BLACK,

                 BLACK, CYBER_Y,  CYBER_Y,  BLACK,    BLACK,
                 BLACK, CYBER_Y,  CYBER_Y,  CYBER_Y,  BLACK,
                 BLACK, CERULEAN, CERULEAN, CERULEAN, BLACK,
                 BLACK, CERULEAN, CERULEAN, CERULEAN, BLACK,
                 RED,   CERULEAN, CERULEAN, CERULEAN, GREEN,
                 BLACK, CYBER_Y,  CYBER_Y, CERULEAN,
                 BLACK, BLACK,    BLACK,

                 BLACK, BLACK, BLACK, BLACK},

    [prgSymL] = {ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA, GOLD_F,
                 ALOHA, ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA, ALOHA,
                 ALOHA, ALOHA, ALOHA,

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
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GREEN,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F, GREEN,
                 GOLD_F, GOLD_F, GOLD_F, GOLD_F,
                 GOLD_F, GOLD_F, GOLD_F,

                 GOLD_F, GOLD_F, GOLD_F, GOLD_F},

    [ja1L] = {WHITE, WHITE, CERULEAN, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE,

              CERULEAN, WHITE, WHITE, CERULEAN,

              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE, WHITE, GREEN,
              WHITE, WHITE, WHITE, WHITE,
              WHITE, WHITE, WHITE,

              CERULEAN, WHITE, WHITE, CERULEAN},

    [ja2L] = {ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN, ASSESSIN,
              ASSESSIN, ASSESSIN, ASSESSIN,

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
                  BLACK, BLACK,    BLACK,

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
                BLACK, BLACK,    RED_VIT, BLACK,
                BLACK, BLACK,    BLACK,

                BLACK, BLACK, BLACK, BLACK,

                CERULEAN, WHITE,     BLACK,   BLACK, BLACK,
                BLACK,    BLACK,     BLACK,   BLACK, BLACK,
                BLACK,    WHITE,     CYBER_Y, BLACK, BLACK,
                BLACK,    MYOGA_P,   GREEN,   BLACK, BLACK,
                BLACK,    CERULEAN,  CYBER_Y, BLACK, GREEN,
                BLACK,    BLACK,     BLACK,   BLACK,
                RED,      LINDERH_G, BLACK,

                BLACK, BLACK, BLACK, BLACK},

    [qwertyL] = {BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS,

                 BTS, BTS, BTS, BTS,

                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS, BTS, GREEN,
                 BTS, BTS, BTS, BTS,
                 BTS, BTS, BTS,

                 BTS, BTS, BTS, BTS},

};
// clang-format on

void set_layer_color(int layer);

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
