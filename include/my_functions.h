/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Functions prototypes
*/

#ifndef INCLUDED_MY_FUNCTIONS_H
    #define INCLUDED_MY_FUNCTIONS_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include "my_struct.h"

// src
int launch_window(void);
void analyse_event(earth_t *earth, window_t *w);
square_t **sort_squares(square_t **squares, int len);
void display_map(sfRenderWindow *w, sphere_t *sphere);
void display_xyz(sfRenderWindow *w, sphere_t *sphere, sfVector2u size);

// init
earth_t *init_earth(void);
window_t *init_window(void);
sphere_t *init_sphere(sfVector2u *size);
square_t *init_square(sfVector2i *p1, sfVector2i *p2, sfVector2i *p4, sfVector2i *p3);
square_t **create_squares(point_t **points);

// free
void free_earth(earth_t *earth);
void free_window(window_t *w);
void free_square(square_t *square);
void free_sphere(sphere_t *sphere);

// maths
sfVector2i project_iso_point(sfVector3f *cartesian, sphere_t *sphere, sfVector2u *size);
void recalculation(window_t *w, sphere_t *sphere);
void apply_rotation(sphere_t *sphere);

// event_key
void analyse_event_key_mouse(earth_t *earth, window_t *w);
void resize_window(window_t *w, sphere_t *sphere);
void mouse_scroll(window_t *w, sphere_t *sphere);
void move_map(window_t *w, sphere_t *sphere);

#endif
