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
    button_texture_t *btn_texture = malloc(sizeof(button_texture_t));

    btn_texture->base_text = sfTexture_createFromFile("assets/b.png", NULL);
    btn_texture->hover_text = sfTexture_createFromFile("assets/hover_button.png", NULL);
    btn_texture->click_text = sfTexture_createFromFile("assets/clicked_button.png", NULL);
    return btn_texture;
}

static void set_text(button_t *button, char *text, sfFont *font)
{
    sfFloatRect rect;

    button->text = sfText_create(font);
    sfText_setCharacterSize(button->text, 25);
    sfText_setString(button->text, text);
    sfText_setFillColor(button->text, sfBlack);
    rect = sfText_getLocalBounds(button->text);
    sfText_setOrigin(button->text,
                     (sfVector2f){
                         rect.size.x / 2.0,
                         rect.size.y / 2.0
                     });
    sfText_setPosition(button->text,
                       (sfVector2f){
                           150,
                           button->position.y + 20
                       });
}

static button_t *create_button(char *text, button_texture_t *textures, sfVector2f *pos, sfFont *font)
{
    button_t *button = malloc(sizeof(button_t));

    button->position.x = pos->x;
    button->position.y = pos->y;
    button->og_pos.x = pos->x;
    button->og_pos.y = pos->y;
    set_text(button, text, font);
    button->base = sfSprite_create(textures->base_text);
    sfSprite_setPosition(button->base, *pos);
    button->hover = sfSprite_create(textures->hover_text);
    sfSprite_setPosition(button->hover, *pos);
    button->click = sfSprite_create(textures->click_text);
    sfSprite_setPosition(button->click, *pos);
    button->display = button->base;
    return button;
}    

void init_button(button_t *buttons[BTN_COUNT], earth_t *earth)
{
    buttons[RESET] = create_button("RESET", earth->btn_textures, &(sfVector2f){0.0, 0.0}, earth->font);
}
