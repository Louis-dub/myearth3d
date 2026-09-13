/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate 2d projection
*/

#include <SFML/Graphics.h>
#include <math.h>

#include "my_struct.h"

sfVector2i project_iso_point(float x, float y, float z, sphere_t *sphere, sfVector2u *size)
{
    sfVector2i point;
    float rx = cos(sphere->delta1 * M_PI / 180) * x - sin(sphere->delta1 * M_PI / 180) * y;
    float ry = sin(sphere->delta1 * M_PI / 180) * x + cos(sphere->delta1 * M_PI / 180) * y;
    float rz = sin(sphere->delta2 * M_PI / 180) * ry + cos(sphere->delta2 * M_PI / 180) * z;

    ry = cos(sphere->delta2 * M_PI / 180) * ry - sin(sphere->delta2 * M_PI / 180) * z;
    point.x = (rx * sphere->zoom) + size->x / 2.0;
    point.y = (ry - rz) * sphere->zoom + size->y / 2.0;
    return point;
}
