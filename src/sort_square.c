/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** sort squares list
*/

#include <stdlib.h>

#include "my_struct.h"

static square_t **fusion(square_t **left, square_t **right, int len)
{
    square_t **squares = malloc(sizeof(square_t*) * (len + 1));
    int i_left = 0;
    int i_right = 0;

    squares[len] = NULL;
    for (int i = 0; i < len; i++) {
        if (!left[i_left]) {
            squares[i] = right[i_right];
            i_right++;
        } else if (!right[i_right]) {
            squares[i] = left[i_left];
            i_left++;
        } else if (left[i_left]->depth < right[i_right]->depth) {
            squares[i] = left[i_left];
            i_left++;
        } else {
            squares[i] = right[i_right];
            i_right++;
        }
    }
    free(left);
    free(right);
    return squares;
}

static square_t **create_copy(square_t **og, int len, int index)
{
    square_t **copy_square = malloc(sizeof(square_t*) * (len + 1));

    copy_square[len] = NULL;
    for (int i = 0; i < len; i++) {
        copy_square[i] = og[index];
        index++;
    }
    return copy_square;
}

square_t **sort_squares(square_t **squares, int len)
{
    if (len == 1)
        return squares;
    square_t **left = create_copy(squares, len / 2, 0);
    square_t **right = create_copy(squares, len - len / 2, len / 2);

    left = sort_squares(left, len / 2);
    right = sort_squares(right, len - len / 2);
    free(squares);
    return fusion(left, right, len);
}
