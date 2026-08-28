/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate 2d projection
*/

#include <math.h>

#include "my_struct.h"

void calculate_map2d(map_t *map)
{
    for (int i = 0; i < map->size; i++) {
        for (int j = 0; j < map->size; j++) {
            map->map_2d[i][j].x = (cosf(map->angle * M_PI / 180) * i - cosf(map->angle * M_PI / 180) * j) * 100 + 400;
            map->map_2d[i][j].y = (sinf(map->angle * M_PI / 180) * i + sinf(map->angle * M_PI / 180) * j - map->map_3d[i][j]) * 100 + 300;
        }
    }
}
