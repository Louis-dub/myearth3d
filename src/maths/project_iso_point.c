/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate 2d projection
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>

#include "my_struct.h"

sfVector2i project_iso_point(sfVector3f *cartesian, sphere_t *sphere, sfVector2u *size)
{
    sfVector2i point;
    float rx = cos(sphere->delta1 * M_PI / 180) * cartesian->x - sin(sphere->delta1 * M_PI / 180) * cartesian->y;
    float ry = sin(sphere->delta1 * M_PI / 180) * cartesian->x + cos(sphere->delta1 * M_PI / 180) * cartesian->y;
    float rz = sin(sphere->delta2 * M_PI / 180) * ry + cos(sphere->delta2 * M_PI / 180) * cartesian->z;

    ry = cos(sphere->delta2 * M_PI / 180) * ry - sin(sphere->delta2 * M_PI / 180) * cartesian->z;
    point.x = (rx - rz) * sphere->zoom + size->x / 2.0;
    point.y = ry * 1.22 * sphere->zoom + size->y / 2.0;
    return point;
}
