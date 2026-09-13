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
void analyse_event(earth_t *earth, window_t *w);
square_t **sort_squares(square_t **squares, int len);

// init
earth_t *init_earth(void);
window_t *init_window(void);
sphere_t *init_sphere(sfVector2u *size);
square_t *init_square(sfVector2i *p1, sfVector2i *p2, sfVector2i *p3, sfVector2i *p4, int index);

// free
void free_earth(earth_t *earth);
void free_window(window_t *w);
void free_square(square_t *square);

// maths
sfVector2i project_iso_point(float x, float y, float z, sphere_t *sphere, sfVector2u *size);

#endif
