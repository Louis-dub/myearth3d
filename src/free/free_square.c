/*
** DUBOIS PROJECT, 2026
** myearth3d
** File decsription:
** free square
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "enums.h"
#include "my_struct.h"

void free_square(square_t *square)
{
    int nb_line = 4;

    if (square->type == TRIANGLE)
        nb_line = 3;
    for (int i = 0; i < nb_line; i++)
        sfVertexArray_destroy(square->lines[i]);
    sfVertexArray_destroy(square->square),
    free(square);
}
