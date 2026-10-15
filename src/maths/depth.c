/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate depth for a square
 */

#include <SFML/System.h>
#include <stddef.h>
#include <math.h>

#include "my_struct.h"
#include "my_functions.h"
#include "enums.h"

static float depth_calculation(point_t **ps, int nb)
{
    float d = 0.0;

    for (int i = 1; i < nb; i++)
        d += (ps[i]->rotate_cartesian.x + ps[i]->rotate_cartesian.y + ps[i]->rotate_cartesian.z);
    return d / nb;
}

static void depth_square(square_t *square, point_t **points)
{
    point_t *ps[4] = {
        points[square->ids[0]],
        points[square->ids[1]],
        points[square->ids[2]],
        points[square->ids[3]]
    };

    square->depth = depth_calculation(ps, 4);
}

static void depth_triangle(square_t *square, point_t **points)
{
    point_t *ps[3] = {
        points[square->ids[0]],
        points[square->ids[1]],
        points[square->ids[2]]
    };

    square->depth = depth_calculation(ps, 3);
}

void depth(square_t **squares, sphere_t *sphere)
{
    for (int i = 0; i < 648; i++) {
        if (squares[i]->type == SQUARE)
            depth_square(squares[i], sphere->points);
        else
            depth_triangle(squares[i], sphere->points);
    }
}
