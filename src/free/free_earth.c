/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free struct all datas
*/

#include <endian.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void free_earth(earth_t *earth)
{
    free_window(earth->w);
    free_map(earth->map);
    free(earth);
}
