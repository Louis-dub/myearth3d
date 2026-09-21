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
    sfVector3f r = {
        sphere->rotation[0][0] * cartesian->x + sphere->rotation[0][1] * cartesian->y + sphere->rotation[0][2] * cartesian->z,
        sphere->rotation[1][0] * cartesian->x + sphere->rotation[1][1] * cartesian->y + sphere->rotation[1][2] * cartesian->z,
        sphere->rotation[2][0] * cartesian->x + sphere->rotation[2][1] * cartesian->y + sphere->rotation[2][2] * cartesian->z,
    };

    point.x = (r.x * (-sqrtf(3.0) / 2) + r.y * (sqrtf(3.0) / 2)) * sphere->zoom;
    point.y = (r.x * (1.0 / 2) + r.y * (1.0 / 2) - r.z) * sphere->zoom;
    point.x += size->x / 2.0;
    point.y += size->y / 2.0;
    return point;
}
