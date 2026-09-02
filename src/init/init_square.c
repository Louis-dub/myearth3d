/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** init a square
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

static void set_v_square(square_t *square)
{
    square->v_square[0].position = square->p[0];
    square->v_square[0].color = sfTransparent;
    square->v_square[1].position = square->p[1];
    square->v_square[1].color = sfTransparent;
    square->v_square[2].position = square->p[2];
    square->v_square[2].color = sfTransparent;
    square->v_square[3].position = square->p[3];
    square->v_square[3].color = sfTransparent;
}

static void set_v_lines(square_t *square)
{
    square->v_line[0].position = square->p[0];
    square->v_line[0].color = sfWhite;
    square->v_line[1].position = square->p[1];
    square->v_line[1].color = sfWhite;
    square->v_line[2].position = square->p[2];
    square->v_line[2].color = sfWhite;
    square->v_line[3].position = square->p[3];
    square->v_line[3].color = sfWhite;
}

static void set_square_array(square_t *square)
{
    square->square = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(square->square, sfTriangles);
    sfVertexArray_append(square->square, square->v_square[0]);
    sfVertexArray_append(square->square, square->v_square[1]);
    sfVertexArray_append(square->square, square->v_square[2]);
    sfVertexArray_append(square->square, square->v_square[0]);
    sfVertexArray_append(square->square, square->v_square[2]);
    sfVertexArray_append(square->square, square->v_square[3]);
}

static void set_lines(square_t *square)
{
    square->lines[0] = sfVertexArray_create();
    sfVertexArray_append(square->lines[0], square->v_line[0]);
    sfVertexArray_append(square->lines[0], square->v_line[1]);
    sfVertexArray_setPrimitiveType(square->lines[0], sfLineStrip);
    square->lines[1] = sfVertexArray_create();
    sfVertexArray_append(square->lines[1], square->v_line[1]);
    sfVertexArray_append(square->lines[1], square->v_line[3]);
    sfVertexArray_setPrimitiveType(square->lines[1], sfLineStrip);
    square->lines[2] = sfVertexArray_create();
    sfVertexArray_append(square->lines[2], square->v_line[3]);
    sfVertexArray_append(square->lines[2], square->v_line[2]);
    sfVertexArray_setPrimitiveType(square->lines[2], sfLineStrip);
    square->lines[3] = sfVertexArray_create();
    sfVertexArray_append(square->lines[3], square->v_line[2]);
    sfVertexArray_append(square->lines[3], square->v_line[0]);
    sfVertexArray_setPrimitiveType(square->lines[3], sfLineStrip);
}

square_t *init_square(sfVector2f *p1, sfVector2f *p2, sfVector2f *p3, sfVector2f *p4)
{
    square_t *square = malloc(sizeof(square_t));

    square->p[0] = *p1;
    square->p[1] = *p2;
    square->p[2] = *p3;
    square->p[3] = *p4;
    set_v_square(square);
    set_v_lines(square);
    set_square_array(square);
    set_lines(square);
    return square;
}
