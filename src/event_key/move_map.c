/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** move the sphere
 */

#include <math.h>

#include "my_functions.h"
#include "my_struct.h"

void move_map(window_t *w, sphere_t *sphere)
{
    float delta_x = w->coor_mouse_pressed.x - w->event.mouseMove.x;
    float delta_y = w->coor_mouse_pressed.y - w->event.mouseMove.y;
    int signx = cos(sphere->angles.y) < 0 ? 1 : -1;
    int signy = cos(sphere->angles.x) < 0 ? -1 : 1;

    sphere->angles.x += delta_x * 0.1 * signx;
    sphere->angles.y += delta_y * 0.1 * signy;
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
    recalculation(w, sphere);
}
