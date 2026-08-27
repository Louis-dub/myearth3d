/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Structures definitions
*/

#ifndef INCLUDED_MY_STRUCT_H
    #define INCLUDED_MY_STRUCT_H
    #include <SFML/Graphics.h>

typedef struct map_s {
    int **map_3d;
    sfVector2f *map_2d;
} map_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2u size;
} window_t;

#endif
