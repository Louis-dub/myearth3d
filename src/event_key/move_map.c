/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move map
*/

#include "my_struct.h"

void move_map(window_t *w, map_t *map)
{
    int x = w->event.mouseMove.x;
    int y = w->event.mouseMove.y;
    int sign = map->delta2 < 0 ? -1 : 1;

    if (x < w->coor_mouse_pressed.x)
        map->delta1 -= 1.0;
    if (x > w->coor_mouse_pressed.x)
        map->delta1 += 1.0;
    if (y < w->coor_mouse_pressed.y)
        map->delta2 += 1.0 * sign;
    if (y > w->coor_mouse_pressed.y)
        map->delta2 -= 1.0 * sign;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
}
