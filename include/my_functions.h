/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Functions prototypes
*/

#ifndef INCLUDED_MY_FUNCTIONS_H
    #define INCLUDED_MY_FUNCTIONS_H
    #include "my_struct.h"

/* src */
int launch_window(void);

/* init */
window_t *init_window(void);
map_t *init_map(void);
earth_t *init_earth(void);

/* free */
void free_window(window_t *w);
void free_map(map_t *map);

#endif
