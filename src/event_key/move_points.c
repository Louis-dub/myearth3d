/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <math.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

static float find_new_z(int new_y, map_t *map, float i, float j)
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
    int delta_y = (w->event.mouseMove.y - w->coor_mouse_pressed.y);
    int i = map->point_move.x;
    int j = map->point_move.y;
    float cx = map->size / 2.0 - 0.5;
    float cy = map->size / 2.0 - 0.5;

    if (!(map->delta2 >= 130 && map->delta2 <= 140) && !(map->delta2 >= 310 && map->delta2 <= 320)) {
        map->map_3d[i][j] = find_new_z((map->map_2d[i][j].y + delta_y) - w->size.y / 2.0, map, i - cx, j - cy);
        if (map->map_3d[i][j] < 0)
            map->map_3d[i][j] = 0.0;
        recalculation(w ,map);
    }
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
