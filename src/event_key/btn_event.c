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
#include <stdio.h>

#include "my_struct.h"
#include "enums.h"

void btn_released(button_t *btn, earth_t *earth)
{
    btn->display = btn->base;
    earth->btn_click = -1;
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
