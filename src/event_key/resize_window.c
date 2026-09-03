/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Resize window and set new view
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

void resize_window(window_t *w, map_t *map)
{
    w->size = sfRenderWindow_getSize(w->window);
    sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
    sfRenderWindow_setView(w->window, w->view);
    calculate_map2d(map, &w->size);
}
