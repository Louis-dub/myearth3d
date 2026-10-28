/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move the sphere
 */

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>

#include "enums.h"
#include "my_struct.h"
#include "my_functions.h"

void set_pos_btn(button_t *buttons[BTN_COUNT], sfVector2f *set_view)
{
    for (int i = 0; i < BTN_COUNT; i++) {
        buttons[i]->position.x = buttons[i]->og_pos.x + set_view->x;
        buttons[i]->position.y = buttons[i]->og_pos.y + set_view->y;
        sfSprite_setPosition(buttons[i]->base, buttons[i]->position);
        sfSprite_setPosition(buttons[i]->hover, buttons[i]->position);
        sfSprite_setPosition(buttons[i]->click, buttons[i]->position);
        sfText_setPosition(buttons[i]->text,
                           (sfVector2f){
                               150 + set_view->x,
                               buttons[i]->position.y + 20
                           });
    }
}

void move_map(earth_t *earth, sfKeyCode code)
{
    sfVector2f *set_view = &earth->w->set_view;
        
    switch (code) {
    case sfKeyLeft:
        set_view->x += 5.5;
        break;
    case sfKeyRight:
        set_view->x -= 5.5;
        break;
    case sfKeyUp:
        set_view->y += 5.5;
        break;
    case sfKeyDown:
        set_view->y -= 5.5;
        break;
    default:
        break;
    }
    set_pos_btn(earth->buttons, set_view);
    resize_window(earth->w, earth->sphere);
}
