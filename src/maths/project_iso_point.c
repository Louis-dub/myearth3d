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

sfVector2i project_iso_point(sfVector3f *rotate_cartesian, sphere_t *sphere, sfVector2u *size)
{
    sfVector2i point;

    point.x = (rotate_cartesian->x * (-sqrtf(3.0) / 2) + rotate_cartesian->y * (sqrtf(3.0) / 2)) * sphere->zoom;
    point.y = (rotate_cartesian->x * (1.0 / 2) + rotate_cartesian->y * (1.0 / 2) - rotate_cartesian->z) * sphere->zoom;
    point.x += size->x / 2.0;
    point.y += size->y / 2.0;
    return point;
}
