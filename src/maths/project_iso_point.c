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
#include <stdio.h>

#include "my_struct.h"

static sfVector3f make_one_rotation(sfVector3f *dir, float x, float y, float z, float d)
{
    sfVector3f rotate;
    float rx = dir->x;
    float ry = dir->y;
    float rz = dir->z;
    
    rotate.x = (rx * rx + (1 - rx * rx) * cos(d)) * x +
               (rx * ry * (1 - cos(d)) - rz * sin(d)) * y +
               (rx * rz * (1 - cos(d)) + ry * sin(d)) * z;
    rotate.y = (rx * ry * (1 - cos(d)) + rz * sin(d)) * x +
               (ry * ry + (1 - ry * ry) * cos(d)) * y +
               (ry * rz * (1 - cos(d)) - rx * sin(d)) * z;
    rotate.z = (rx * rz * (1 - cos(d)) - ry * sin(d)) * x +
               (ry * rz * (1 - cos(d)) + rx * sin(d)) * y +
               (rz * rz + (1 - rz * rz) * cos(d)) * z;
    return rotate;
}

static sfVector3f make_double_rotation(sfVector3f *cartesian, sphere_t *sphere)
{
    float x = cartesian->x;
    float y = cartesian->y;
    float z = cartesian->z;
    float d1 = sphere->angles.x * M_PI / 180.0;
    float d2 = sphere->angles.y * M_PI / 180.0;
    sfVector3f rotate = make_one_rotation(&(sfVector3f){0, 0, 1}, cartesian->x, cartesian->y, cartesian->z, sphere->angles.x);

    rotate = make_one_rotation(&(sfVector3f){(float){-sqrt(3) / 2.0}, sqrt(3) / 2.0, 0.0},
                               rotate.x, rotate.y, rotate.z, sphere->angles.y);
    return rotate;
}

sfVector2i project_iso_point(sfVector3f *cartesian, sphere_t *sphere, sfVector2u *size)
{
    sfVector2i point;
    sfVector3f r = make_double_rotation(cartesian, sphere);

    printf("x: %f, y: %f, z: %f\n", cartesian->x, cartesian->y, cartesian->z);
    printf("rx: %f, ry: %f, rz: %f\n", r.x, r.y, r.z);
    point.x = (r.x * (-sqrtf(3.0) / 2) + r.y * (sqrtf(3.0) / 2)) * sphere->zoom;
    point.y = (r.x * (1.0 / 2) + r.y * (1.0 / 2) - r.z) * sphere->zoom;
    point.x += size->x / 2.0;
    point.y += size->y / 2.0;
    return point;
}
