/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** set zoom mhen scrolled
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

void mouse_scroll(window_t *w, map_t *map)
{
    if (w->event.mouseWheelScroll.delta > 0)
        map->zoom += 2;
    else
        map->zoom -= 2;
    if (map->zoom <= 30)
        map->zoom = 30;
    if (map->zoom >= 200)
        map->zoom = 200;
}
