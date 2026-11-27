/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free menu screen
 */

#include <CSFML/Graphics.h>
#include <stdlib.h>

#include "my_struct.h"

void free_menu(menu_t *menu)
{
    sfText_destroy(menu->title);
    free(menu);
}
