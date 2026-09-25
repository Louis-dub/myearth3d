/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move points
 */

#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

static void set_point(point_t *point, float r, float theta, float phi)
{
    point->cartesian = (sfVector3f){
        r * sin(theta * M_PI / 180) * cos(phi * M_PI / 180),
        r * sin(theta * M_PI / 180) * sin(phi * M_PI / 180),
        r * cos(theta * M_PI / 180)
    };
}

void move_point(window_t *w, sphere_t *sphere)
{
    float x = w->coor_mouse_pressed.x - w->size.x / 2.0;
    float y = w->coor_mouse_pressed.y - w->size.y / 2.0;
    int id = w->touch_point;
    sfVector2f add_radius_2d = {
        w->event.mouseMove.x - w->coor_mouse_pressed.x,
        w->event.mouseMove.y - w->coor_mouse_pressed.y
    };
    float sign = add_radius_2d.x * x < 0 || add_radius_2d.y * y < 0 ? -1.0 : 1.0;
    float d = sqrt(pow(add_radius_2d.x, 2) + pow(add_radius_2d.y, 2)) / sphere->zoom * sign;

    sphere->points[id]->spherical.x += d;
    if (sphere->points[id]->spherical.x < 1.0)
        sphere->points[id]->spherical.x = 1.0;
    set_point(sphere->points[id], sphere->points[id]->spherical.x,
              sphere->points[id]->spherical.y, sphere->points[id]->spherical.z);
    recalculation(w, sphere);
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
