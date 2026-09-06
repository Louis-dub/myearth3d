/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void display_map(sfRenderWindow *w, map_t *map)
{
    for (int i = 0; map->squares[i] != NULL; i++) {
        sfRenderWindow_drawVertexArray(w, map->squares[i]->square, NULL);
        for (int j = 0; j < 4; j++)
            sfRenderWindow_drawVertexArray(w, map->squares[i]->lines[j], NULL);
    }
}
