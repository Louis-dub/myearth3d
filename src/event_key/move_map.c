/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move map
*/

#include <math.h>

#include "my_struct.h"

void move_map(window_t *w, map_t *map)
{
    float delta_x = w->event.mouseMove.x - w->coor_mouse_pressed.x;
    float delta_y = w->event.mouseMove.y - w->coor_mouse_pressed.y;
    float signx = cos(map->delta2 * M_PI / 180) < 0 ? 1.0 : -1.0;
    float signy = cos(map->delta1 * M_PI / 180) < 0 ? 1.0 : -1.0;

    map->delta1 += delta_x * 0.5 * signx;
    map->delta2 += delta_y * -0.3;
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
