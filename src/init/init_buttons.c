/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init buttons
 */

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <stdlib.h>

#include "my_struct.h"
#include "enums.h"

button_texture_t *load_btn_texture(void)
{
    button_texture_t *btn_texture = malloc(sizeof(button_t));

    btn_texture->base_text = sfTexture_createFromFile("assets/b.png", NULL);
    btn_texture->hover_text = sfTexture_createFromFile("assets/hover_button.png", NULL);
    btn_texture->click_text = sfTexture_createFromFile("assets/clicked_button.png", NULL);
    return btn_texture;
}

static button_t *create_button(char *text, button_texture_t *textures, sfVector2f *pos)
{
    button_t *button = malloc(sizeof(button_t));

    button->text = text;
    button->base = sfSprite_create(textures->base_text);
    sfSprite_setPosition(button->base, *pos);
    button->hover = sfSprite_create(textures->hover_text);
    sfSprite_setPosition(button->hover, *pos);
    button->click = sfSprite_create(textures->click_text);
    sfSprite_setPosition(button->click, *pos);
    button->display = button->base;
    button->position = pos;
    return button;
}    

void init_button(button_t *buttons[BTN_COUNT], earth_t *earth)
{
    buttons[RESET] = create_button("RESET", earth->btn_textures, &(sfVector2f){0.0, 0.0});
}
