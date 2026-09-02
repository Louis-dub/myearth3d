/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** analyse events
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

void analyse_event(window_t *w, map_t *map)
{   
    if (w->event.type == sfEvtClosed)
        sfRenderWindow_close(w->window);
    if (w->event.type == sfEvtResized) {
        w->size = sfRenderWindow_getSize(w->window);
        sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
        sfRenderWindow_setView(w->window, w->view);
        calculate_map2d(map, &w->size);
    }
    if (w->event.type == sfEvtMouseButtonPressed) {
        printf("x: %d, y: %d\n", w->event.mouseButton.x, w->event.mouseButton.y);
        printf("px: %g, py: %g\n", map->map_2d[2][2].x, map->map_2d[2][2].y);
    }
}
