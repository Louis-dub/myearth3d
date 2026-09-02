/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** create all map's square
*/

#include <SFML/Graphics.h>

sfVertexArray *create_square(int x, int y, sfVector2f **map)
{
    sfVertexArray *square = sfVertexArray_create();
    sfVertex v1 = {map[x][y], sfWhite};
    sfVertex v2 = {map[x + 1][y], sfWhite};
    sfVertex v3 = {map[x][y + 1], sfWhite};
    sfVertex v4 = {map[x + 1][y + 1], sfWhite};

    sfVertexArray_setPrimitiveType(square, sfTriangles);
    sfVertexArray_append(square, v1);
    sfVertexArray_append(square, v2);
    sfVertexArray_append(square, v3);
    sfVertexArray_append(square, v1);
    sfVertexArray_append(square, v3);
    sfVertexArray_append(square, v4);
    return square;
}
