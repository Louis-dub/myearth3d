/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init_window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowBase.h>
#include <stdlib.h>

#include "my_struct.h"

window_t *init_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode v = {800, 600, 32};

    w->window = sfRenderWindow_create(
       v,
       "myearth3d",
       sfDefaultStyle,
       NULL
    );
    sfRenderWindow_setFramerateLimit(w->window, 60);
    return w;
}
