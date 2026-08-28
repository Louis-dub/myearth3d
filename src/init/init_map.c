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

    map->size = 2;
    map->map_3d = malloc(sizeof(int*) * map->size);
    for (int i = 0; i < map->size; i++) {
        map->map_3d[i] = malloc(sizeof(int) * map->size);
        for (int j = 0; j < map->size; j++)
            map->map_3d[i][j] = 0;
    }
    map->map_2d = malloc(sizeof(sfVector2f*) * map->size);
    for (int i = 0; i < map->size; i++)
        map->map_2d[i] = malloc(sizeof(sfVector2f) * map->size);
    map->angle = 30;
    return map;
}
