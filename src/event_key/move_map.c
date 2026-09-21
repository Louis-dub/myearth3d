/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** move the sphere
 */

#include "my_functions.h"
#include "my_struct.h"

void move_map(window_t *w, sphere_t *sphere)
{
    float delta_x = w->coor_mouse_pressed.x - w->event.mouseMove.x;
    float delta_y = w->coor_mouse_pressed.y - w->event.mouseMove.y;

    sphere->angles.x += delta_x * 0.5;
    sphere->angles.y += delta_y * 0.5;
    w->coor_mouse_pressed.x = w->event.mouseMove.x;
    w->coor_mouse_pressed.y = w->event.mouseMove.y;
    apply_rotation(sphere);
    recalculation(w, sphere);
}
