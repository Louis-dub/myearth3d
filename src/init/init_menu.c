/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init menu
*/

#include <CSFML/Graphics/Sprite.h>
#include <CSFML/Graphics/Texture.h>
#include <stdlib.h>

#include "my_struct.h"

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    
    menu->bg_text = sfTexture_createFromFile("assets/select_world.png", NULL);
    menu->bg_sprite = sfSprite_create(menu->bg_text);
    return menu;
}
