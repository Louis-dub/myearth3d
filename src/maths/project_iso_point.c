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

    point.x = cartesian->y * sphere->zoom + size->x / 2.0;
    point.y = -(cartesian->z * sphere->zoom) + size->y / 2.0;
    return point;
}
