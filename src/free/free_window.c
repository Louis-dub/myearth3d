/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** free_window
*/

#include <CSFML/Graphics.h>
#include <CSFML/Window.h>
#include <stdlib.h>

#include "enums.h"
#include "my_struct.h"

void free_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    sfView_destroy(w->view);
    sfCursor_destroy(w->cursors[HAND]);
    sfCursor_destroy(w->cursors[ARROW]);
    free(w);
}
