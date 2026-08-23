/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** launch csfml window
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

int launch_window(void)
{
    window_t *w = init_window();

    while (sfRenderWindow_isOpen(w->window)) {
        sfRenderWindow_clear(w->window, sfBlack);
        while (sfRenderWindow_pollEvent(w->window, &w->event))
            if (w->event.type == sfEvtClosed)
                sfRenderWindow_close(w->window);
        w->size = sfRenderWindow_getSize(w->window);
        sfRenderWindow_display(w->window);
    }
    free_window(w);
    return 0;
}
