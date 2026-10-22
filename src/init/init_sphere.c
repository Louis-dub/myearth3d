/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate cartseian coordonates
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <stdlib.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"

static int find_fold(float r1, float r2, float r3, float r4)
{
    if (r1 >= r2 && r1 >= r3 && r1 >= r4)
        return 1;
    if (r2 >= r3 && r2 >= r4)
        return 0;
    if (r3 >= r4)
        return 1;
    return 0;
}

square_t **create_squares(point_t **points, sphere_t *sphere)
{
    square_t **squares = malloc(sizeof(square_t*) * 648);
    int index = 0;
    int p[4] = {0, 0, 0, 0};

    for (int i = 1; i < 37; i++) {
        squares[index] = init_square(&points[0]->screen, &points[i]->screen, &points[i % 36 + 1]->screen, NULL,
                                     0, i, i % 36 + 1, 0, 0);
        index++;
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 36; j++) {
            int id = 1 + i * 36 + j;
            p[0] = id;
            p[1] = id + 1 - (j / 35 * 36);
            p[2] = id + 36 + 1 - (j / 35 * 36);
            p[3] = id + 36;
            squares[index] = init_square(&points[p[0]]->screen, &points[p[1]]->screen, &points[p[2]]->screen, &points[p[3]]->screen,
                                         p[0], p[1], p[2], p[3], find_fold(
                                                                               points[p[0]]->spherical.x,
                                                                               points[p[1]]->spherical.x,
                                                                               points[p[2]]->spherical.x,
                                                                               points[p[3]]->spherical.x
                                                                           ));
            index++;
        }
    }
    for (int i = 577; i < 613; i++) {
        squares[index] = init_square(&points[613]->screen, &points[i]->screen, &points[i + 1 == 613 ? 577 : i + 1]->screen, NULL,
                                     613, i, i + 1 == 613 ? 577 : i + 1, 0, 0);
        index++;
    }
    depth(squares, sphere);
    return sort_squares(squares, 648);
}

static point_t *create_point(float r, float theta, float phi, sphere_t *sphere, sfVector2u *size)
{
    point_t *point = malloc(sizeof(point_t));

    point->spherical = (sfVector3f){r, theta, phi};
    point->cartesian = (sfVector3f){
        r * sin(theta * M_PI / 180) * cos(phi * M_PI / 180),
        r * sin(theta * M_PI / 180) * sin(phi * M_PI / 180),
        r * cos(theta * M_PI / 180)
    };
    set_cartesian(&point->cartesian, &point->rotate_cartesian, sphere);
    point->screen = project_iso_point(&point->cartesian, sphere, size);
    return point;
}

static point_t **create_points(float r, sphere_t *sphere, sfVector2u *size)
{
    point_t **points = malloc(sizeof(point_t*) * 614);
    int index = 1;

    points[0] = create_point(r, 0, 0, sphere, size);
    points[613] = create_point(r, 180, 0, sphere, size);
    for (int i = 1; i < 18; i++) {
        for (int j = 0; j < 36; j++) {
            points[index] = create_point(r, i * 10, j * 10, sphere, size);
            index++;
        }
    }
    return points;
}

static void init_axes(sphere_t *sphere, sfVector2u *size)
{
    float norme = sqrt(pow(-sqrt(3) / 2.0, 2) + pow(sqrt(3) / 2.0, 2));
    point_t *point = create_point(sphere->r, -45, 45, sphere, size);

    sphere->axes[0].x = point->cartesian.x;
    sphere->axes[0].y = point->cartesian.y;
    sphere->axes[0].z = point->cartesian.z;
    sphere->axes[1] = (sfVector3f){
        (-sqrt(3) / 2) / norme,
        (sqrt(3) / 2) / norme,
        0
    };
    free(point);
}

static void set_matrix_identity(float m[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            m[i][j] = i == j ? 1.0 : 0.0;
}

sphere_t *init_sphere(sfVector2u *size)
{
    sphere_t *sphere = malloc(sizeof(sphere_t));

    sphere->r = 1;
    set_matrix_identity(sphere->rotation);
    sphere->angles.x = 0.0;
    sphere->angles.y = 0.0;
    sphere->zoom = 200;
    sphere->points = create_points(sphere->r, sphere, size);
    sphere->squares = create_squares(sphere->points, sphere);
    init_axes(sphere, size);
    return sphere;
}
