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
    sfTexture_destroy(menu->bg_text);
    sfSprite_destroy(menu->bg_sprite);
    sfText_destroy(menu->title);
    free(menu);
}
