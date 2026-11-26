/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** launch csfml window
*/

#include <CSFML/Graphics.h>
#include <CSFML/Graphics/RenderWindow.h>
#include <stddef.h>

#include "my_functions.h"
#include "my_struct.h"
#include "enums.h"

int launch_window(void)
{
    earth_t *earth = init_earth();

    while (sfRenderWindow_isOpen(earth->w->window)) {
        sfRenderWindow_clear(earth->w->window, (sfColor){120, 120, 120});
        while (sfRenderWindow_pollEvent(earth->w->window, &earth->w->event))
            analyse_event(earth, earth->w);
        if (earth->screen == MENU)
            display_menu(earth->w->window, earth->menu);
        else {
            display_map(earth->w->window, earth->sphere);
            display_button(earth);
        }
        sfRenderWindow_display(earth->w->window);
    }
    free_earth(earth);
    return 0;
}
