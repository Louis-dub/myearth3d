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
    float rx = cosh(map->delta1 * M_PI / 180) * x - sinh(map->delta1 * M_PI / 180) * y;
    float ry = sinh(map->delta1 * M_PI / 180) * x + cosh(map->delta1 * M_PI / 180) * y;
    float rz = sinh(map->delta2 * M_PI / 180) * ry + cosh(map->delta2 * M_PI / 180) * z;

    ry = cosh(map->delta2 * M_PI / 180) * ry - sinh(map->delta2 * M_PI / 180) * z;
    point.x = rx * 50 + 400;
    point.y = (ry - rz) * 50 + 300;
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
