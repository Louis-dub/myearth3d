/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free struct all datas
 */

#include <CSFML/Graphics.h>

#include "enums.h"
#include "my_struct.h"

void free_btn_text(button_texture_t *btn_texture)
{
    sfTexture_destroy(btn_texture->base_text);
    sfTexture_destroy(btn_texture->click_text);
    sfTexture_destroy(btn_texture->hover_text);
    free(btn_texture);
}

static void free_button(button_t *btn)
{
    sfText_destroy(btn->text);
    sfSprite_destroy(btn->base);
    sfSprite_destroy(btn->hover);
    sfSprite_destroy(btn->click);
    free(btn);
}

void free_buttons(button_t *buttons[BTN_COUNT])
{
    free_button(buttons[RESET]);
}
