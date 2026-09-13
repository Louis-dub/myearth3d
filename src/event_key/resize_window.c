/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Resize window and set new view
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

static void recalculation(window_t *w, sphere_t *sphere)
{
    for (int i = 0; i < 648; i++)
        free_square(sphere->squares[i]);
    free(sphere->squares);
    for (int i = 0; i < 614; i++)
        sphere->points[i]->screen = project_iso_point(&sphere->points[i]->cartesian, sphere, &w->size);
    sphere->squares = create_squares(sphere->points);
}

void resize_window(window_t *w, sphere_t *sphere)
{
    w->size = sfRenderWindow_getSize(w->window);
    sfView_setCenter(w->view, (sfVector2f){(float){w->size.x / 2.0}, (float){w->size.y / 2.0}});
    sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
    sfRenderWindow_setView(w->window, w->view);
    recalculation(w, sphere);
}
