/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

static void mouse_pressed(window_t *w, map_t *map)
{
    printf("xm: %g, ym: %g\n", map->map_2d[0][0].x, map->map_2d[0][0].y);
    printf("xs: %g, ys: %g\n", map->squares[0][0].v_line[0].position.x, map->squares[0][0].v_line[0].position.y);
    printf("xc: %d, yc: %d\n", w->event.mouseButton.x, w->event.mouseButton.y);
}

void analyse_event_key_mouse(earth_t *earth, window_t *w)
{
    switch (w->event.type) {
        case sfEvtResized:
            resize_window(earth->w);
            break;
        case sfEvtMouseWheelScrolled:
             mouse_scroll(w, earth->map);
            break;
        case sfEvtMouseButtonPressed:
            mouse_pressed(w, earth->map);
            break;
        case sfEvtMouseButtonReleased:
            w->mouse_pressed = false;
            break;
        default:
            break;
    }
    for (int i = 0; earth->map->squares[i] != NULL; i++)
        free_square(earth->map->squares[i]);
    free(earth->map->squares);
    calculate_map2d(earth->map, &w->size);
    earth->map->squares = create_squares(earth->map);
}
