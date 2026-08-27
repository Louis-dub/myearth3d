/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init map
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>

#include "my_struct.h"

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->map_3d = malloc(sizeof(int*) * 15);
    for (int i = 0; i < 15; i++) {
        map->map_3d[i] = malloc(sizeof(int) * 15);
        for (int j = 0; j < 15; j++)
            map->map_3d[i][j] = 0;
    }
    map->map_2d = malloc(sizeof(sfVector2f*) * 15 * 15);
    for (int i = 0; i < 15; i++)
        map->map_2d[i] = malloc(sizeof(sfVector2f) * 15);
    map->angle = 30;
    map->size = 15;
    return map;
}
