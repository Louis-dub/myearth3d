/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void display_map(sfRenderWindow *w, sphere_t *sphere)
{
    int nb_line = 4;

    for (int i = 0; i < 648; i++) {
        sfRenderWindow_drawVertexArray(w, sphere->squares[i]->square, NULL);
        if (sphere->squares[i]->type == SQUARE)
            nb_line = 4;
        else
            nb_line = 3;
        for (int j = 0; j < nb_line; j++)
            sfRenderWindow_drawVertexArray(w, sphere->squares[i]->lines[j], NULL);
    }
}
