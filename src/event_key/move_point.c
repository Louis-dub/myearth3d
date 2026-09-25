/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move points
 */

#include <SFML/Graphics.h>
#include <math.h>

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

static void check_next_radius(point_t *point, point_t **points, int id)
{
    int line = id / 36;
    int t = line == 0 ? 0 : (line - 1) * 36 + id % 36;
    int b = line == 16 ? 613 : (line + 1) * 36 + id % 36;
    int l = (id - 1) % 36 == 0 ? id + 35 : id - 1;
    int r = id % 36 == 0 ? id - 35 : id + 1;

    if (point->spherical.x < points[t]->spherical.x + 0.01 &&
        point->spherical.x > points[t]->spherical.x - 0.01)
        point->spherical.x = points[t]->spherical.x;
    if (point->spherical.x < points[b]->spherical.x + 0.01 &&
        point->spherical.x > points[b]->spherical.x - 0.01)
        point->spherical.x = points[b]->spherical.x;
    if (point->spherical.x < points[l]->spherical.x + 0.01 &&
        point->spherical.x > points[l]->spherical.x - 0.01)
        point->spherical.x = points[l]->spherical.x;
    if (point->spherical.x < points[r]->spherical.x + 0.01 &&
        point->spherical.x > points[r]->spherical.x - 0.01)
        point->spherical.x = points[r]->spherical.x;
}

static void check_next_for_pole(point_t *point, point_t **points, int id)
{
    int start = id == 0 ? 1 : 577;
    int end = id == 0 ? 37 : 613;
    
    for (int i = start; i < end; i++)
        if (point->spherical.x < points[i]->spherical.x + 0.01 &&
            point->spherical.x > points[i]->spherical.x - 0.01)
            point->spherical.x = points[i]->spherical.x;
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
    if (id != 0 && id != 613)
        check_next_radius(sphere->points[id], sphere->points, id);
    else
        check_next_for_pole(sphere->points[id], sphere->points, id);
    if (sphere->points[id]->spherical.x < 1.0)
        sphere->points[id]->spherical.x = 1.0;
    if (sphere->points[id]->spherical.x > 3.0)
        sphere->points[id]->spherical.x = 3.0;
    set_point(sphere->points[id], sphere->points[id]->spherical.x,
              sphere->points[id]->spherical.y, sphere->points[id]->spherical.z);
    recalculation(w, sphere);
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
}
