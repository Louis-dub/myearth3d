/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** set zoom mhen scrolled
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

void mouse_scroll(window_t *w, sphere_t *sphere)
{
    if (w->event.mouseWheelScroll.delta > 0)
        sphere->zoom += 2;
    else
        sphere->zoom -= 2;
    if (sphere->zoom <= 100)
        sphere->zoom = 100;
    if (sphere->zoom >= 400)
        sphere->zoom = 400;
    recalculation(w, sphere);
}
