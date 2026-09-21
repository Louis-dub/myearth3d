/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate 2d projection
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Vector3.h>
#include <math.h>

#include "my_struct.h"

sfVector3f make_one_rotation(sfVector3f *dir, float x, float y, float z, float d)
{
    float q[4] = {cos(d / 2), dir->x * sin(d / 2), dir->y * sin(d / 2), dir->z * sin(d / 2)};
    float p[4] = {0, x, y, z};
    float q1[4] = {q[0], -q[1], -q[2], -q[3]};
    float temp[4] = {
        (q[0] * p[0]) - (q[1] * p[1] + q[2] * p[2] + q[3] * p[3]),
        q[0] * p[1] + p[0] * q[1] + (q[2] * p[3] - q[3] * p[2]),
        q[0] * p[2] + p[0] * q[2] + (q[3] * p[1] - q[1] * p[3]),
        q[0] * p[3] + p[0] * q[3] + (q[1] * p[2] - q[2] * p[1])
    };
    sfVector3f rotate = {
        temp[0] * q1[1] + q1[0] * temp[1] + (temp[2] * q1[3] - temp[3] * q1[2]),
        temp[0] * q1[2] + q1[0] * temp[2] + (temp[3] * q1[1] - temp[1] * q1[3]),
        temp[0] * q1[3] + q1[0] * temp[3] + (temp[1] * q1[2] - temp[2] * q1[1])
    };

    return rotate;
}

static sfVector3f make_double_rotation(sfVector3f *cartesian, sphere_t *sphere)
{
    float x = cartesian->x;
    float y = cartesian->y;
    float z = cartesian->z;
    float d1 = sphere->angles.x * M_PI / 180.0;
    float d2 = sphere->angles.y * M_PI / 180.0;
    sfVector3f rotate = make_one_rotation(&sphere->axes[0],
                                          x, y, z, d1);

    rotate = make_one_rotation(&sphere->axes[1],
                       rotate.x, rotate.y, rotate.z, d2);
    return rotate;
}

sfVector2i project_iso_point(sfVector3f *cartesian, sphere_t *sphere, sfVector2u *size)
{
    sfVector2i point;
    sfVector3f r = make_double_rotation(cartesian, sphere);

    point.x = (r.x * (-sqrtf(3.0) / 2) + r.y * (sqrtf(3.0) / 2)) * sphere->zoom;
    point.y = (r.x * (1.0 / 2) + r.y * (1.0 / 2) - r.z) * sphere->zoom;
    point.x += size->x / 2.0;
    point.y += size->y / 2.0;
    return point;
}
