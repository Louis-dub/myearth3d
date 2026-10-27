/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free struct all datas
*/

#include <CSFML/Graphics/Texture.h>
#include <CSFML/Graphics/Types.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

static void free_buttons(button_t *btn_texture)
{
    sfTexture_destroy(btn_texture->base_text);
    sfTexture_destroy(btn_texture->click_text);
    sfTexture_destroy(btn_texture->hover_text);
    free(btn_texture);
}    

void free_earth(earth_t *earth)
{
    free_window(earth->w);
    free_sphere(earth->sphere);
    free_buttons(earth->btn_textures);
    free(earth);
}
