/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate 2d projection
*/

#include <SFML/System/Vector2.h>
#include <math.h>

#include "my_struct.h"

static sfVector2f project_iso_point(int x, int y, float z, map_t *map, sfVector2u *size)
{
    sfVector2f point;
    float rx = cos(map->delta1 * M_PI / 180) * x - sin(map->delta1 * M_PI / 180) * y;
    float ry = sin(map->delta1 * M_PI / 180) * x + cos(map->delta1 * M_PI / 180) * y;
    float rz = sin(map->delta2 * M_PI / 180) * ry + cos(map->delta2 * M_PI / 180) * z;

    ry = cos(map->delta2 * M_PI / 180) * ry - sin(map->delta2 * M_PI / 180) * z;
    point.x = rx * map->zoom;
    point.y = (ry - rz) * map->zoom;
    return point;
}

void calculate_map2d(map_t *map, sfVector2u *size)
{
    float cx = 5 / 2.0 - 0.5;
    float cy = 5 / 2.0 - 0.5;

    for (int i = 0; i < map->size; i++)
        for (int j = 0; j < map->size; j++)
            map->map_2d[i][j] = project_iso_point(i - cx, j - cy, map->map_3d[i][j], map, size);            
}
