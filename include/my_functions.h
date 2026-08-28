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

/* src */
int launch_window(void);

/* init */
earth_t *init_earth(void);
window_t *init_window(void);
map_t *init_map(void);

/* free */
void free_earth(earth_t *earth);
void free_window(window_t *w);
void free_map(map_t *map);

/* display_map */
void calculate_map2d(map_t *map);
void display_map(sfRenderWindow *w, map_t *map);
sfVertexArray *create_square(int x, int y, sfVector2f **map);

#endif
