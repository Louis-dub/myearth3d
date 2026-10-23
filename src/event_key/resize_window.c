/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Resize window and set new view
*/

#include <CSFML/Graphics.h>

#include "my_functions.h"
#include "my_struct.h"

void resize_window(window_t *w, sphere_t *sphere)
{
    w->size = sfRenderWindow_getSize(w->window);
    sfView_setCenter(w->view, (sfVector2f){
        (float){w->size.x / 2.0} + w->set_view.x,
        (float){w->size.y / 2.0} + w->set_view.y});
    sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
    sfRenderWindow_setView(w->window, w->view);
    recalculation(w, sphere);
}
