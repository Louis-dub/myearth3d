/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Menu
*/

#include <CSFML/Graphics.h>
#include <stdio.h>

#include "my_struct.h"

void display_menu(sfRenderWindow *w, menu_t *menu)
{
    sfRenderWindow_drawText(w, menu->title, NULL);
    sfRenderWindow_drawSprite(w, menu->btn_create->display, NULL);
    sfRenderWindow_drawText(w, menu->btn_create->text, NULL);
}
