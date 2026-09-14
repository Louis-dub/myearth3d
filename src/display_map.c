/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display Map
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

#include "enums.h"
#include "my_struct.h"

void display_map(sfRenderWindow *w, sphere_t *sphere)
{
    int nb_line = 4;

    for (int i = 0; i < 648; i++) {
        //printf("i: %d\n", i);
        sfRenderWindow_drawVertexArray(w, sphere->squares[i]->square, NULL);
        if (sphere->squares[i]->type == SQUARE)
            nb_line = 4;
        else
            nb_line = 3;
        //printf("nb_line: %d\n", nb_line);
        for (int j = 0; j < nb_line; j++)
            sfRenderWindow_drawVertexArray(w, sphere->squares[i]->lines[j], NULL);
    }
}
