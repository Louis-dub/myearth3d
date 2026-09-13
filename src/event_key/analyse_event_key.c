/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Analyse key and mouse events
*/

#include <SFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

void analyse_event_key_mouse(earth_t *earth, window_t *w)
{
    switch (w->event.type) {
        case sfEvtResized:
            resize_window(w, earth->sphere);
            break;
        default:
            break;
    }
}
