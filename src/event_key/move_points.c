/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_struct.h"

static float find_new_z(int new_y, map_t *map, int i, int j)
{
    float dy = (float){new_y} / (map->zoom);
    float ry = sin(map->delta1 * M_PI / 180) * i + cos(map->delta1 * M_PI / 180) * j;
    float dividend = 0.0;
    float divider = -sin(map->delta2 * M_PI / 180) - cos(map->delta2 * M_PI / 180);

    ry *= (cos(map->delta2 * M_PI / 180) - sin(map->delta2 * M_PI / 180));
    dividend = dy - ry;
    return dividend / divider;
}

void move_points(window_t *w, map_t *map)
{
    float sign = cos(map->delta1 * M_PI / 180) >= 0 ? 1.0 : -1.0;
    int delta_y = (w->event.mouseMove.y - w->coor_mouse_pressed.y) * sign;
    int i = map->point_move.x;
    int j = map->point_move.y;
    float cx = 5 / 2.0 - 0.5;
    float cy = 5 / 2.0 - 0.5;

    map->map_3d[i][j] = find_new_z(map->map_2d[i][j].y + delta_y, map, i - cx, j - cy);
    //exit(1);
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
