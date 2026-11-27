/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init menu
*/

#include <CSFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

static void create_title(menu_t *menu, sfFont *font, sfVector2u *w_size)
{
    sfFloatRect rect;

    menu->title = sfText_create(font);
    sfText_setCharacterSize(menu->title, 60);
    sfText_setString(menu->title, "MyEarth3D");
    sfText_setFillColor(menu->title, sfWhite);
    sfText_setOutlineThickness(menu->title, 1.0);
    sfText_setOutlineColor(menu->title, sfBlack);
    rect = sfText_getLocalBounds(menu->title);
    sfText_setOrigin(menu->title, (sfVector2f){
        rect.size.x / 2.0,
        rect.size.y / 2.0,
    });
    sfText_setPosition(menu->title, (sfVector2f){
        w_size->x / 2.0,
        w_size->y * 0.1
    });    
}

menu_t *init_menu(sfFont *font, sfVector2u *w_size, button_t *btn)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->btn_create = btn;
    create_title(menu, font, w_size);
    return menu;
}
