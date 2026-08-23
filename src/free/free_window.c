/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** free_window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

void free_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    free(w);
}
