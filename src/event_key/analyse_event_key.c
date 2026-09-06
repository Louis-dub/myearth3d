/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "enums.h"
#include "my_functions.h"
#include "my_struct.h"

void recalculation(window_t *w, map_t *map)
{
    for (int i = 0; map->squares[i] != NULL; i++)
        free_square(map->squares[i]);
    free(map->squares);
    calculate_map2d(map, &w->size);
    map->squares = create_squares(map, &w->size);
}

static void mouse_pressed(window_t *w, map_t *map)
{
    int x = w->event.mouseButton.x;
    int y = w->event.mouseButton.y;

    w->if_mouse_pressed = MAP;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
    for (int i = 0; i < map->size; i++) {
        for (int j = 0; j < map->size; j++) {
            if (map->map_2d[i][j].x - 10 <= x && map->map_2d[i][j].x + 10 >= x &&
                map->map_2d[i][j].y - 10 <= y && map->map_2d[i][j].y + 10 >= y) {
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
            resize_window(w, earth->map);
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
}
