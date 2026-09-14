/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Recalculate 2d projection
 */

#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void recalculation(window_t *w, sphere_t *sphere)
{
    for (int i = 0; i < 648; i++)
        free_square(sphere->squares[i]);
    free(sphere->squares);
    for (int i = 0; i < 614; i++)
        sphere->points[i]->screen = project_iso_point(&sphere->points[i]->cartesian, sphere, &w->size);
    sphere->squares = create_squares(sphere->points);
}
