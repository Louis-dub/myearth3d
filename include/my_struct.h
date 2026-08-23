/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Structures definitions
*/

#ifndef INCLUDED_MY_STRUCT_H
    #define INCLUDED_MY_STRUCT_H
    #include <SFML/Graphics.h>

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
} window_t;

#endif
