/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include "my_struct.h"

void move_points(window_t *w, map_t *map)
{
    int delta_y = w->event.mouseMove.y - w->coor_mouse_pressed.y;
    int i = map->point_move.x;
    int j = map->point_move.y;

    map->map_3d[i][j] += delta_y * -0000.1;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
