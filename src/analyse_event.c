/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** analyse events
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>

#include "my_functions.h"
#include "my_struct.h"

void analyse_event(window_t *w)
{   
    if (w->event.type == sfEvtClosed)
        sfRenderWindow_close(w->window);
    if (w->event.type == sfEvtResized) {
        w->size = sfRenderWindow_getSize(w->window);
        sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
        sfRenderWindow_setView(w->window, w->view);
    }
}
