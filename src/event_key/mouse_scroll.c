/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** set zoom mhen scrolled
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void mouse_scroll(window_t *w, map_t *map)
{
    if (w->event.mouseWheelScroll.delta > 0)
        map->zoom += 2;
    else
        map->zoom -= 2;
    if (map->zoom <= 10)
        map->zoom = 10;
    if (map->zoom >= 100)
        map->zoom = 100;
    calculate_map2d(map, &w->size);
    for (int i = 0; map->squares[i] != NULL; i++)
        free_square(map->squares[i]);
    free(map->squares);
    map->squares = create_squares(map);
}
