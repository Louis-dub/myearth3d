/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>
#include <stdbool.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"
#include "enums.h"

static void reset_point(point_t *point)
{
    float r = point->spherical.x;
    float theta = point->spherical.y;
    float phi = point->spherical.z;
    
    point->cartesian = (sfVector3f){
        r * sin(theta * M_PI / 180) * cos(phi * M_PI / 180),
        r * sin(theta * M_PI / 180) * sin(phi * M_PI / 180),
        r * cos(theta * M_PI / 180)
    };
}

void btn_released(button_t *btn, earth_t *earth)
{
    btn->display = btn->base;
    earth->btn_click = -1;
    earth->w->set_view.x = 0.0;
    earth->w->set_view.y = 0.0;
    earth->sphere->zoom = 200;
    for (int i = 0; i < 614; i++) {
        earth->sphere->points[i]->spherical.x = earth->sphere->r;
        reset_point(earth->sphere->points[i]);
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            earth->sphere->rotation[i][j] = i == j ? 1.0 : 0.0;
    apply_rotation(earth->sphere);
    resize_window(earth->w, earth->sphere);
    set_pos_btn(earth->buttons, &earth->w->set_view);
}

void btn_hover(sfEvent *event, button_t *buttons[BTN_COUNT], window_t *w)
{
    int x = event->mouseMove.position.x + w->set_view.x;
    int y = event->mouseMove.position.y + w->set_view.y;
    int xb = 0;
    int yb = 0;

    for (int i = 0; i < BTN_COUNT; i++) {
        xb = buttons[i]->position.x;
        yb = buttons[i]->position.y;
        if (xb <= x && x <= xb + 300 && yb <= y && y <= yb + 48) {
            buttons[i]->display = buttons[i]->hover;
            sfRenderWindow_setMouseCursor(w->window, w->cursors[HAND]);
        } else {
            buttons[i]->display = buttons[i]->base;
            sfRenderWindow_setMouseCursor(w->window, w->cursors[ARROW]);
        }
    }
}
