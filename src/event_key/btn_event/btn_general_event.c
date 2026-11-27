/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Events for all buttons
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>
#include <stdbool.h>

#include "my_functions.h"
#include "my_struct.h"
#include "enums.h"

void btn_released(button_t *btn, earth_t *earth)
{
    btn->display = btn->base;
    earth->btn_click = -1;
    btn->function(earth);
}

void btn_hover(sfEvent *event, button_t *buttons[BTN_COUNT], window_t *w, screen_t mode)
{
    int x = event->mouseMove.position.x + w->set_view.x;
    int y = event->mouseMove.position.y + w->set_view.y;
    int xb = 0;
    int yb = 0;
    int start = mode == MENU ? 0 : 1;
    int end = mode == EDIT ? BTN_COUNT : 1;
    bool not_hand = true;
    
    for (int i = start; i < end; i++) {
        xb = buttons[i]->position.x;
        yb = buttons[i]->position.y;
        if (xb <= x && x <= xb + 300 && yb <= y && y <= yb + 48) {
            buttons[i]->display = buttons[i]->hover;
            sfRenderWindow_setMouseCursor(w->window, w->cursors[HAND]);
            not_hand = false;
        } else {
            buttons[i]->display = buttons[i]->base;
            if (not_hand)
                sfRenderWindow_setMouseCursor(w->window, w->cursors[ARROW]);
        }
    }
}
