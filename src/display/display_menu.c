/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Menu
*/

#include <CSFML/Graphics.h>
#include <stdio.h>

#include "my_struct.h"

void display_menu(sfRenderWindow *w, menu_t *menu, button_t *btn_create)
{
    //sfRenderWindow_drawSprite(w, menu->bg_sprite, NULL);
    sfRenderWindow_drawText(w, menu->title, NULL);
    sfRenderWindow_drawSprite(w, btn_create->display, NULL);
    sfRenderWindow_drawText(w, btn_create->text, NULL);
}
