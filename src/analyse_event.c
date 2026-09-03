/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** analyse events
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "my_functions.h"
#include "my_struct.h"

void analyse_event(earth_t *earth, window_t *w)
{   
    if (w->event.type == sfEvtClosed)
        sfRenderWindow_close(w->window);
    analyse_event_key_mouse(earth, &w->event);
 }
