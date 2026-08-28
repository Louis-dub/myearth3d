/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** launch csfml window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>

#include "my_functions.h"
#include "my_struct.h"

void display_square(sfRenderWindow *w)
{
    sfRectangleShape *square = sfRectangleShape_create();

    sfRectangleShape_setPosition(square, (sfVector2f){350, 250});
    sfRectangleShape_setSize(square, (sfVector2f){100, 100});
    sfRectangleShape_setOutlineThickness(square, 5.0);
    sfRectangleShape_setOutlineColor(square, sfRed);
    sfRectangleShape_setFillColor(square, sfTransparent);
    sfRenderWindow_drawRectangleShape(w, square, NULL);
    sfRectangleShape_destroy(square);
}

int launch_window(void)
{
    earth_t *earth = init_earth();

    while (sfRenderWindow_isOpen(earth->w->window)) {
        sfRenderWindow_clear(earth->w->window, sfBlack);
        while (sfRenderWindow_pollEvent(earth->w->window, &earth->w->event))
            if (earth->w->event.type == sfEvtClosed)
                sfRenderWindow_close(earth->w->window);
        earth->w->size = sfRenderWindow_getSize(earth->w->window);
        display_map(earth->w->window, earth->map);
        sfRenderWindow_display(earth->w->window);
    }
    free_earth(earth);
    return 0;
}
