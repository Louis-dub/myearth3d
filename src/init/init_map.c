/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init map
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

square_t **create_squares(map_t *map)
{
    int len = (map->size - 1) * (map->size - 1);
    square_t **squares = malloc(sizeof(square_t*) * (len + 1));

    squares[len] = NULL;
    int index = 0;
    for (int i = 0; i < map->size - 1; i++) {
        for (int j = 0; j < map->size - 1; j++) {
            squares[index] = init_square(&map->map_2d[i][j],
                                         &map->map_2d[i + 1][j],
                                         &map->map_2d[i][j + 1],
                                         &map->map_2d[i + 1][j + 1]);
            index++;
        }
    }
    return squares;
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->size = 5;
    map->map_3d = malloc(sizeof(int*) * (map->size + 1));
    map->map_3d[map->size] = NULL;
    for (int i = 0; i < map->size; i++) {
        map->map_3d[i] = malloc(sizeof(int) * (map->size));
        for (int j = 0; j < map->size; j++)
            map->map_3d[i][j] = 0.0;
    }
    map->map_3d[2][1] = 1.0;
    map->map_3d[3][1] = 2.0;
    map->map_2d = malloc(sizeof(sfVector2f*) * (map->size + 1));
    map->map_2d[map->size] = NULL;
    for (int i = 0; i < map->size; i++)
        map->map_2d[i] = malloc(sizeof(sfVector2f) * map->size);
    map->delta1 = 45.0;
    map->delta2 = 25.0;
    map->zoom = 100;
    calculate_map2d(map, &(sfVector2u){800, 600});
    map->squares = create_squares(map);
    return map;
}
