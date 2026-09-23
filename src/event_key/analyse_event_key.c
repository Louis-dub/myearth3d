/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

static void mouse_pressed(window_t *w, sphere_t *sphere)
{
    int x = w->event.mouseButton.x;
    int y = w->event.mouseButton.y;

    w->if_mouse_pressed = MAP;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
    for (int i = 0; i < 614; i++) {
        if (sphere->points[i]->screen.x - 10 <= x && sphere->points[i]->screen.x + 10 >= x &&
            sphere->points[i]->screen.y - 10 <= y && sphere->points[i]->screen.y + 10 >= y) {
            w->if_mouse_pressed = POINT;
            w->touch_point = i;
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
            break;
        default:
            break;
    }
}
