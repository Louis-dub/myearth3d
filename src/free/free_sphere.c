/*
** DUBOIS PROJECT, 2026
** myearth3d
** File decsription:
** free square
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void free_sphere(sphere_t *sphere)
{
    for (int i = 0; i < 614; i++)
        free(sphere->points[i]);
    free(sphere->points);
    for (int i = 0; i < 648; i++)
        free_square(sphere->squares[i]);
    free(sphere->squares);
    free(sphere);
}
