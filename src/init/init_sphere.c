/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate cartseian coordonates
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"



static point_t *create_point(float r, float theta, float phi, sphere_t *sphere, sfVector2u *size)
{
    point_t *point = malloc(sizeof(point_t));

    point->r = r;
    point->theta = theta;
    point->phi = phi;
    point->x = r * sin(theta) * cos(phi);
    point->y = r * sin(theta) * sin(phi);
    point->z = r * cos(theta);
    point->screen = project_iso_point(point->x, point->y, point->z, sphere, size);
    return point;
}

static point_t **create_points(float r, sphere_t *sphere, sfVector2u *size)
{
    point_t **points = malloc(sizeof(point_t*) * 614);
    int index = 1;

    points[0] = create_point(r, 0, 0, sphere, size);
    points[613] = create_point(-r, 0, 0, sphere, size);
    for (int i = 1; i < 18; i++) {
        for (int j = 0; j < 36; j++) {
            points[index] = create_point(r, i * 10, j * 10, sphere, size);
            index++;
        }
    }
    return points;
}

sphere_t *init_sphere(sfVector2u *size)
{
    sphere_t *sphere = malloc(sizeof(sphere_t));

    sphere->r = 100.0;
    sphere->delta1 = 45.0;
    sphere->delta2 = 25.0;
    sphere->zoom = 100;
    sphere->points = create_points(sphere->r, sphere, size);
    return sphere;
}
