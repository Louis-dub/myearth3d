/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init_window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

window_t *init_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode v = {800, 600, 32};
    w->view = sfView_createFromRect((sfFloatRect){0, 0, 800, 600});

    w->window = sfRenderWindow_create(
       v,
       "myearth3d",
       sfDefaultStyle,
       NULL
    );
    sfRenderWindow_setView(w->window, w->view);
    sfRenderWindow_setFramerateLimit(w->window, 60);
    w->mouse_pressed = false;
    return w;
}
