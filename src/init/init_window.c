/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init_window
*/

#include <CSFML/Graphics.h>
#include <CSFML/Graphics/RenderWindow.h>
#include <CSFML/Window/WindowBase.h>
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
    w->if_mouse_pressed = NONE;
    return w;
}
