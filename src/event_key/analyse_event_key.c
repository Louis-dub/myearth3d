/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "enums.h"
#include "my_functions.h"
#include "my_struct.h"

static void mouse_pressed(window_t *w, map_t *map)
{
    int x = w->event.mouseButton.x;
    int y = w->event.mouseButton.y;

    w->if_mouse_pressed = MAP;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
    printf("xm: %d, ym: %d\n", x, y);
    for (int i = 0; i < map->size; i++) {
        for (int j = 0; j < map->size; j++) {
            if (map->map_2d[i][j].x + w->size.x / 2.0 - 10 <= x && map->map_2d[i][j].x + w->size.x / 2.0 + 10 >= x &&
                map->map_2d[i][j].y + w->size.y / 2.0 - 10 <= y && map->map_2d[i][j].y + w->size.y / 2.0 + 10 >= y) {
                w->if_mouse_pressed = POINT;
                map->point_move.x = i;
                map->point_move.y = j;
            }
        }
    }
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
            w->if_mouse_pressed = NONE;
            break;
        case sfEvtMouseMoved:
            if (w->if_mouse_pressed == MAP)
                move_map(w, earth->map);
            if (w->if_mouse_pressed == POINT)
                move_points(w, earth->map);
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
