/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <CSFML/Graphics.h>
#include <CSFML/Window.h>
#include <stdbool.h>

#include "enums.h"
#include "my_functions.h"
#include "my_struct.h"

static int check_btn_click(button_t *buttons[BTN_COUNT], window_t *w)
{
    int x = w->event.mouseButton.position.x + w->set_view.x;
    int y = w->event.mouseButton.position.y + w->set_view.y;
    int xb = 0;
    int yb = 0;

    for (int i = 0; i < BTN_COUNT; i++) {
        xb = buttons[i]->position.x;
        yb = buttons[i]->position.y;
        if (xb <= x && x <= xb + 300 && yb <= y && y <= yb + 48) {
            buttons[i]->display = buttons[i]->click;
            return i;
        }
    }
    return -1;
}

static void mouse_pressed(window_t *w, sphere_t *sphere, earth_t *earth)
{
    int x = w->event.mouseButton.position.x;
    int y = w->event.mouseButton.position.y;
    int t = 0;
    int id = 0;

    earth->btn_click = check_btn_click(earth->buttons, w);
    if (earth->btn_click != -1)
        return;
    w->if_mouse_pressed = MAP;
    w->coor_mouse_pressed.x = x;
    w->coor_mouse_pressed.y = y;
    for (int i = 0; i < 648; i++) {
        t = sphere->squares[i]->type == SQUARE ? 4 : 3;
        for (int j = 0; j < t; j++) {
            id = sphere->squares[i]->ids[j];
            if ((sphere->points[id]->screen.x - w->set_view.x) - 10 <= x && (sphere->points[id]->screen.x - w->set_view.x) + 10 >= x &&
                (sphere->points[id]->screen.y - w->set_view.y) - 10 <= y && (sphere->points[id]->screen.y - w->set_view.y) + 10 >= y) {
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
        mouse_pressed(w, earth->sphere, earth);
        break;
    case sfEvtMouseButtonReleased:
        if (earth->btn_click != -1)
            btn_released(earth->buttons[earth->btn_click], earth);
        w->if_mouse_pressed = NONE;
        break;
    case sfEvtMouseMoved:
        if (w->if_mouse_pressed == MAP)
            rotate_map(w, earth->sphere);
        if (w->if_mouse_pressed == POINT)
            move_point(w, earth->sphere);
        if (w->if_mouse_pressed == NONE && earth->btn_click == -1)
            btn_hover(&w->event, earth->buttons, w);
        break;
    case sfEvtKeyPressed:
        move_map(earth, w->event.key.code);
        break;
    default:
        break;
    }
}
