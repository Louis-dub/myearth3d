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
            map->map_2d[i][j].x = cosf(map->angle) * i - cosf(map->angle) * j;
            map->map_2d[i][j].y = sinf(map->angle) * i + sinf(map->angle) * j + map->map_3d[i][j];
        }
    }
}
