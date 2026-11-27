/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init_window
*/

#include <CSFML/Graphics.h>
#include <CSFML/Window.h>
#include <stdlib.h>

#include "enums.h"
#include "my_struct.h"

window_t *init_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode v = {800, 600, 32};

    w->size.x = 800;
    w->size.y = 600;
    w->view = sfView_create();
    sfView_setCenter(w->view, (sfVector2f){400, 300});
    sfView_setSize(w->view, (sfVector2f){800, 600});
    w->window = sfRenderWindow_create(v, "myearth3d", sfDefaultStyle, sfWindowed, NULL);
    sfRenderWindow_setView(w->window, w->view);
    sfRenderWindow_setFramerateLimit(w->window, 60);
    w->set_view.x = 0.0;
    w->set_view.y = 0.0;
    w->if_mouse_pressed = NONE;
    w->cursors[HAND] = sfCursor_createFromSystem(sfCursorHand);
    w->cursors[ARROW] = sfCursor_createFromSystem(sfCursorArrow);
    w->background[MENU] = (sfColor){34, 12, 6};
    w->background[EDIT] = (sfColor){120, 120, 120};
    return w;
}
