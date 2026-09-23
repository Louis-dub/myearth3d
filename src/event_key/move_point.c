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

void move_point(window_t *w, sphere_t *sphere)
{
    sfVector2f add_radius_2d = {
        w->event.mouseMove.x - w->coor_mouse_pressed.x,
        w->event.mouseMove.y - w->coor_mouse_pressed.y
    };
    int d = sqrt(pow(add_radius_2d.x, 2) + pow(add_radius_2d.y, 2));

    recalculation(w, sphere);
}
