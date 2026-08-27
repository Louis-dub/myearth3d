/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free struct map
*/

#include <stdlib.h>

#include "my_struct.h"

void free_map(map_t *map)
{
    for (int i = 0; i < 15; i++)
        free(map->map_3d[i]);
    free(map->map_3d);
    free(map->map_2d);
    free(map);
}
