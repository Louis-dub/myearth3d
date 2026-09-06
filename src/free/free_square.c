/*
** DUBOIS PROJECT, 2026
** myearth3d
** File decsription:
** free square
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

void free_square(square_t *square)
{
    for (int i = 0; i < 4; i++)
        sfVertexArray_destroy(square->lines[i]);
    sfVertexArray_destroy(square->square),
    free(square);
}
