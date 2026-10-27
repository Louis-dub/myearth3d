/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Butttons
 */

#include <CSFML/Graphics.h>

#include "my_struct.h"
#include "enums.h"

void display_button(earth_t *earth)
{
    for (int i = 0; i < BTN_COUNT; i++)
        sfRenderWindow_drawSprite(earth->w->window, earth->buttons[i]->display, NULL);
}
