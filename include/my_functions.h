/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Functions prototypes
*/

#ifndef INCLUDED_MY_FUNCTIONS_H
    #define INCLUDED_MY_FUNCTIONS_H
    #include <SFML/Graphics.h>
    #include "my_struct.h"

// src
int launch_window(void);
void calculate_map2d(map_t *map, sfVector2u *size);
void analyse_event(earth_t *earth, window_t *w);

// init
earth_t *init_earth(void);
window_t *init_window(void);
map_t *init_map(void);
square_t **create_squares(map_t *map);
square_t *init_square(sfVector2f *p1, sfVector2f *p2, sfVector2f *p3, sfVector2f *p4);

// free
void free_earth(earth_t *earth);
void free_window(window_t *w);
void free_map(map_t *map);
void free_square(square_t *square);

/* display_map */
void display_map(sfRenderWindow *w, map_t *map);
sfVertexArray *create_square(int x, int y, sfVector2f **map);

// event_key
void analyse_event_key_mouse(earth_t *earth, window_t *w);
void resize_window(window_t *w);
void mouse_scroll(window_t *w, map_t *map);

#endif
