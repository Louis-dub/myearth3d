/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Structures definitions
*/

#ifndef INCLUDED_MY_STRUCT_H
    #define INCLUDED_MY_STRUCT_H
    #include <CSFML/Graphics.h>
    #include <CSFML/System.h>
    #include <stdbool.h>

#include "enums.h"

typedef struct color_s {
    sfColor color;
    sfTexture *texture;
} color_t;

typedef struct square_s {
    type_square_t type;
    sfVector2f p[4];
    int ids[4];
    sfVertex v_square[4];
    sfVertex v_line[4];
    sfVertexArray *square;
    sfVertexArray *lines[4];
    float depth;
    int id_t;
} square_t;

typedef struct point_s {
    sfVector3f spherical;
    sfVector3f cartesian;
    sfVector3f rotate_cartesian;
    sfVector2i screen;
} point_t;

typedef struct sphere_s {
    float r;
    point_t **points;
    square_t **squares;
    sfVector2f angles;
    sfVector3f axes[2];
    float rotation[3][3];
    int zoom;
    color_t colors[5];
} sphere_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u size;
    sfView *view;
    sfVector2f set_view;
    mouse_pressed_t if_mouse_pressed;
    sfVector2i coor_mouse_pressed;
    int touch_point;
} window_t;

typedef struct button_s {
    char *text;
    sfSprite *base;
    sfSprite *hover;
    sfSprite *click;
} button_t;

typedef struct button_texture_s {
    sfTexture *base_text;
    sfTexture *hover_text;
    sfTexture *click_text;
} button_texture_t;

typedef struct earth_s {
    window_t *w;
    sphere_t *sphere;
    button_texture_t *btn_textures;
    button_t *buttons[BTN_COUNT];
} earth_t;

#endif
