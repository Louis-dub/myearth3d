/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Move the sphere
 */

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>

#include "my_struct.h"
#include "my_functions.h"

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
    resize_window(earth->w, earth->sphere);
}
