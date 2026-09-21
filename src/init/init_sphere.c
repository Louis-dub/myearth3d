/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate cartseian coordonates
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"

square_t **create_squares(point_t **points)
{
    square_t **squares = malloc(sizeof(square_t*) * 648);
    int index = 0;
    int p[4] = {0, 0, 0, 0};

    for (int i = 1; i < 37; i++) {
        squares[index] = init_square(&points[0]->screen, &points[i]->screen, &points[i % 36 + 1]->screen, NULL);
        index++;
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 36; j++) {
            int id = 1 + i * 36 + j;
            p[0] = id;
            p[1] = id + 1 - (j / 35 * 36);
            p[2] = id + 36 + 1 - (j / 35 * 36);
            p[3] = id + 36;
            squares[index] = init_square(&points[p[0]]->screen, &points[p[1]]->screen, &points[p[2]]->screen, &points[p[3]]->screen);
            index++;
        }
    }
    for (int i = 577; i < 613; i++) {
        squares[index] = init_square(&points[613]->screen, &points[i]->screen, &points[i % 612 + (i / 612 * 577)]->screen, NULL);
        index++;
    }
    
    return squares;
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
    sphere->angles.x = 0.0;
    sphere->angles.y = 0.0;
    sphere->zoom = 200;
    sphere->points = create_points(sphere->r, sphere, size);
    sphere->squares = create_squares(sphere->points);
    init_axes(sphere, size);
    set_matrix_identity(sphere->rotation);
    return sphere;
}
