/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Structures definitions
*/

#ifndef INCLUDED_MY_STRUCT_H
    #define INCLUDED_MY_STRUCT_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stdbool.h>

    #include "enums.h"

typedef struct square_s {
    type_square_t type;
    sfVector2f p[4];
    sfVertex v_square[4];
    sfVertex v_line[4];
    sfVertexArray *square;
    sfVertexArray *lines[4];
    int depth;
} square_t;

typedef struct point_s {
    sfVector3f spherical;
    sfVector3f cartesian;
    sfVector2i screen;
} point_t;

typedef struct sphere_s {
    float r;
    point_t **points;
    square_t **squares;
    float delta1;
    float delta2;
    int zoom;
} sphere_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u size;
    sfView *view;
    mouse_pressed_t if_mouse_pressed;
    sfVector2i coor_mouse_pressed;
} window_t;

typedef struct earth_s {
    window_t *w;
    sphere_t *sphere;
} earth_t;

#endif
