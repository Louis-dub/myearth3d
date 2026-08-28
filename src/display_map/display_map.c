/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

void display_map(sfRenderWindow *w, map_t *map)
{
    sfVertexArray *square = NULL;

    printf("New grid\n");
    calculate_map2d(map);
    for (int i = 0; i < map->size - 1; i++) {
        for (int j = 0; j < map->size - 1; j++) {
            square = create_square(i, j, map->map_2d);
            sfRenderWindow_drawVertexArray(w, square, NULL);
            sfVertexArray_destroy(square);
        }
    }
}
