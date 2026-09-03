/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>

#include "my_functions.h"
#include "my_struct.h"

void analyse_event_key_mouse(earth_t *earth, sfEvent *event)
{
    switch (event->type) {
        case sfEvtResized:
            resize_window(earth->w, earth->map);
            break;
        default:
            break;
    }
}
