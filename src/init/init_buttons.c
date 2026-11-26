/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init buttons
 */

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/System/Vector2.h>
#include <stdlib.h>
#include <string.h>

#include "my_functions.h"
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
    sfFloatRect mid_btn = sfSprite_getLocalBounds(button->base);

    button->text = sfText_create(font);
    sfText_setCharacterSize(button->text, 25);
    sfText_setString(button->text, text);
    sfText_setFillColor(button->text, sfBlack);
    rect = sfText_getLocalBounds(button->text);
    sfText_setOrigin(button->text, (sfVector2f){
        rect.size.x / 2.0,
        rect.size.y / 2.0
    });
    sfText_setPosition(button->text, (sfVector2f){
        button->position.x + mid_btn.size.x / 2.0,
        button->position.y + mid_btn.size.y / 2.0 - 5
    });
}

static void pos_is_middle(button_t *btn)
{
    sfFloatRect rect = sfSprite_getLocalBounds(btn->base);

    btn->position.x -= (rect.size.x / 2.0);
    btn->position.y -= (rect.size.y / 2.0);
    btn->og_pos.x = btn->position.x;
    btn->og_pos.y = btn->position.y;
}

static button_t *create_button(char *text, button_texture_t *textures, sfVector2f *pos, sfFont *font,
                               void (*function)(earth_t*))
{
    button_t *button = malloc(sizeof(button_t));

    button->position.x = pos->x;
    button->position.y = pos->y;
    button->og_pos.x = pos->x;
    button->og_pos.y = pos->y;
    button->base = sfSprite_create(textures->base_text);
    button->hover = sfSprite_create(textures->hover_text);
    button->click = sfSprite_create(textures->click_text);
    if (strcmp("CREATE MAP", text) == 0)
        pos_is_middle(button);
    set_text(button, text, font);
    sfSprite_setPosition(button->base, button->position);
    sfSprite_setPosition(button->hover, button->position);
    sfSprite_setPosition(button->click, button->position);
    button->display = button->base;
    button->function = function;
    return button;
}    

void init_button(button_t *buttons[BTN_COUNT], earth_t *earth)
{
    void (*btn_functions[3])(earth_t *earth) = {
        btn_create_map, btn_go_menu, btn_reset
    };
    
    buttons[CREATE_MAP] = create_button("CREATE MAP", earth->btn_textures, &(sfVector2f){
        earth->w->size.x / 2.0,
        earth->w->size.y * 0.25
    }, earth->font, btn_functions[0]);
    buttons[GO_MENU] = create_button("MENU", earth->btn_textures, &(sfVector2f){0.0, 0.0}, earth->font,
                                     btn_functions[1]);
    buttons[RESET] = create_button("RESET", earth->btn_textures, &(sfVector2f){0.0, 48.0}, earth->font,
                                   btn_functions[2]);
}
