/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>

#include "enums.h"
#include "my_functions.h"
#include "my_struct.h"

static void mouse_pressed(window_t *w, sphere_t *sphere)
{
    int x = w->event.mouseButton.x;
    int y = w->event.mouseButton.y;
    int t = 0;
    int id = 0;

    w->if_mouse_pressed = MAP;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
    for (int i = 647; i >= 0; i--) {
        if (sphere->squares[i]->type == SQUARE)
            t = 4;
        else
            t = 3;
        for (int j = 0; j < t; j++) {
            id = sphere->squares[i]->ids[j];
            if (sphere->points[id]->screen.x - 10 <= x && sphere->points[id]->screen.x + 10 >= x &&
                sphere->points[id]->screen.y - 10 <= y && sphere->points[id]->screen.y + 10 >= y) {
                w->if_mouse_pressed = POINT;
                w->touch_point = id;
            }
        }
    }
}

void analyse_event_key_mouse(earth_t *earth, window_t *w)
{
    switch (w->event.type) {
    case sfEvtResized:
            resize_window(w, earth->sphere);
            break;
        case sfEvtMouseWheelScrolled:
            mouse_scroll(w, earth->sphere);
            break;
        case sfEvtMouseButtonPressed:
            mouse_pressed(w, earth->sphere);
            break;
        case sfEvtMouseButtonReleased:
            w->if_mouse_pressed = NONE;
            break;
        case sfEvtMouseMoved:
            if (w->if_mouse_pressed == MAP)
                move_map(w, earth->sphere);
            if (w->if_mouse_pressed == POINT)
                move_point(w, earth->sphere);
            break;
        default:
            break;
    }
}
