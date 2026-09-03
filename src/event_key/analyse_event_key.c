/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

static void mouse_pressed(window_t *w, map_t *map)
{
    
}

void analyse_event_key_mouse(earth_t *earth, window_t *w)
{
    switch (w->event.type) {
        case sfEvtResized:
            resize_window(earth->w, earth->map);
            break;
        case sfEvtMouseWheelScrolled:
             mouse_scroll(w, earth->map);
            break;
        case sfEvtMouseButtonPressed:
            mouse_pressed(w, earth->map);
            break;
        case sfEvtMouseButtonReleased:
            w->mouse_pressed = false;
            break;
        default:
            break;
    }
}
