/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Structures definitions
*/

#ifndef INCLUDED_MY_STRUCT_H
    #define INCLUDED_MY_STRUCT_H
    #include <SFML/Graphics.h>

typedef struct square_s {
    sfVector2f p[4];
    sfVertex v_square[4];
    sfVertex v_line[4];
    sfVertexArray *square;
    sfVertexArray *lines[4];
} square_t;

typedef struct map_s {
    int **map_3d;
    sfVector2f **map_2d;
    float angle;
    int size;
    square_t **squares;
} map_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u size;
    sfView *view;
} window_t;

typedef struct earth_s {
    window_t *w;
    map_t *map;
} earth_t;

#endif
