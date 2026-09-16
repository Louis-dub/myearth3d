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
    float delta_x =  w->coor_mouse_pressed.x - w->event.mouseMove.x;
    int signx = cos(sphere->d2 * M_PI / 180) < 0 ? 1 : -1;

    sphere->d1 += delta_x * 0.5 * signx;
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    recalculation(w, sphere);
}
