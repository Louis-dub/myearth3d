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

int launch_window(void)
{
    earth_t *earth = init_earth();

    while (sfRenderWindow_isOpen(earth->w->window)) {
        sfRenderWindow_clear(earth->w->window, sfBlack);
        while (sfRenderWindow_pollEvent(earth->w->window, &earth->w->event))
            analyse_event(earth->w);
        display_map(earth->w->window, earth->map);
        sfRenderWindow_display(earth->w->window);
    }
    free_earth(earth);
    return 0;
}
