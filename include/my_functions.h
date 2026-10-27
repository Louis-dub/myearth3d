/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Functions prototypes
*/

#ifndef INCLUDED_MY_FUNCTIONS_H
    #define INCLUDED_MY_FUNCTIONS_H
    #include <CSFML/Graphics.h>
    #include <CSFML/System.h>
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
square_t *init_square(sfVector2i *p1, sfVector2i *p2, sfVector2i *p3, sfVector2i *p4,
                      int i1, int i2, int i3, int i4, int fold, sphere_t *sphere);
square_t **create_squares(point_t **points, sphere_t *sphere);
void init_textures(sphere_t *sphere);
button_texture_t *load_btn_texture(void);
void init_button(button_t *buttons[BTN_COUNT], earth_t *earth);

// free
void free_earth(earth_t *earth);
void free_window(window_t *w);
void free_square(square_t *square);
void free_sphere(sphere_t *sphere);
void free_btn_text(button_texture_t *btn_texture);
void free_buttons(button_t *buttons[BTN_COUNT]);

// maths
sfVector2i project_iso_point(sfVector3f *cartesian, sphere_t *sphere, sfVector2u *size);
void recalculation(window_t *w, sphere_t *sphere);
void apply_rotation(sphere_t *sphere);
void set_cartesian(sfVector3f *cartesian, sfVector3f *rotate_cartesian, sphere_t *sphere);
void depth(square_t **squares, sphere_t *sphere);

// event_key
void analyse_event_key_mouse(earth_t *earth, window_t *w);
void resize_window(window_t *w, sphere_t *sphere);
void mouse_scroll(window_t *w, sphere_t *sphere);
void rotate_map(window_t *w, sphere_t *sphere);
void move_point(window_t *w, sphere_t *sphere);
void move_map(earth_t *earth, sfKeyCode code);

#endif
