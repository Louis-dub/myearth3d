/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init a square
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

#include "my_struct.h"

static void set_v_square(square_t *square, sfVector2i *p3)
{
    square->v_square[0].position = square->p[0];
    square->v_square[0].color = sfCyan;
    square->v_square[1].position = square->p[1];
    square->v_square[1].color = sfCyan;
    square->v_square[2].position = square->p[2];
    square->v_square[2].color = sfCyan;
    if (p3) {
        square->v_square[3].position = square->p[3];
        square->v_square[3].color = sfCyan;
    }
}

static void set_v_lines(square_t *square, sfVector2i *p3)
{
    square->v_line[0].position = square->p[0];
    square->v_line[0].color = sfBlack;
    square->v_line[1].position = square->p[1];
    square->v_line[1].color = sfBlack;
    square->v_line[2].position = square->p[2];
    square->v_line[2].color = sfBlack;
    if (p3) {
        square->v_line[3].position = square->p[3];
        square->v_line[3].color = sfBlack;
    }
}

static void set_square_array(square_t *square, sfVector2i *p3)
{
    square->square = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(square->square, sfTriangles);
    sfVertexArray_append(square->square, square->v_square[1]);
    sfVertexArray_append(square->square, square->v_square[2]);
    sfVertexArray_append(square->square, square->v_square[0]);
    if (p3) {
        sfVertexArray_append(square->square, square->v_square[3]);
        sfVertexArray_append(square->square, square->v_square[0]);
        sfVertexArray_append(square->square, square->v_square[2]);
    }
}

static void set_lines(square_t *square, sfVector2i *p3)
{
    square->lines[0] = sfVertexArray_create();
    sfVertexArray_append(square->lines[0], square->v_line[0]);
    sfVertexArray_append(square->lines[0], square->v_line[1]);
    sfVertexArray_setPrimitiveType(square->lines[0], sfLineStrip);
    square->lines[1] = sfVertexArray_create();
    sfVertexArray_append(square->lines[1], square->v_line[1]);
    sfVertexArray_append(square->lines[1], square->v_line[2]);
    sfVertexArray_setPrimitiveType(square->lines[1], sfLineStrip);
    square->lines[2] = sfVertexArray_create();
    if (p3) {
        sfVertexArray_append(square->lines[2], square->v_line[2]);
        sfVertexArray_append(square->lines[2], square->v_line[3]);
        sfVertexArray_setPrimitiveType(square->lines[2], sfLineStrip);
        square->lines[3] = sfVertexArray_create();
        sfVertexArray_append(square->lines[3], square->v_line[3]);
        sfVertexArray_append(square->lines[3], square->v_line[0]);
        sfVertexArray_setPrimitiveType(square->lines[3], sfLineStrip);
    } else {
        sfVertexArray_append(square->lines[2], square->v_line[2]);
        sfVertexArray_append(square->lines[2], square->v_line[0]);
        sfVertexArray_setPrimitiveType(square->lines[2], sfLineStrip);
        square->lines[3] = NULL;
    }
}

square_t *init_square(sfVector2i *p1, sfVector2i *p2, sfVector2i *p4, sfVector2i *p3)
{
    square_t *square = malloc(sizeof(square_t));

    square->p[0] = (sfVector2f){(float){p1->x}, (float){p1->y}};
    square->p[1] = (sfVector2f){(float){p2->x}, (float){p2->y}};
    square->p[2] = (sfVector2f){(float){p3->x}, (float){p3->y}};
    if (p3)
        square->p[3] = (sfVector2f){(float){p4->x}, (float){p4->y}};
    set_v_square(square, p3);
    set_v_lines(square, p3);
    set_square_array(square, p3);
    set_lines(square, p3);
    return square;
}
