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
    float rx = cos(sphere->d1 * M_PI / 180) * cartesian->x - sin(sphere->d1 * M_PI / 180) * cartesian->y;
    float ry = sin(sphere->d1 * M_PI / 180) * cartesian->x + cos(sphere->d1 * M_PI / 180) * cartesian->y;
    float rz = sin(sphere->d2 * M_PI / 180) * rx + cos(sphere->d2 * M_PI / 180) * cartesian->z;

    rx = cos(sphere->d2 * M_PI / 180) * rx - sin(sphere->d2 * M_PI / 180) * cartesian->z;
    point.x = (rx * (-sqrtf(3.0) / 2) + ry * (sqrtf(3.0) / 2)) * sphere->zoom;
    point.y = (rx * (1.0 / 2) + ry * (1.0 / 2) - rz) * sphere->zoom;
    point.x += size->x / 2.0;
    point.y += size->y / 2.0;
    return point;
}
