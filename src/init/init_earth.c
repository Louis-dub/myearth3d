/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** init all datas
*/

#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

earth_t *init_earth(void)
{
    earth_t *earth = malloc(sizeof(earth_t));

    earth->map = init_map();
    earth->w = init_window();
    return earth;
}
