/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** init all datas
*/

#include <CSFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"
#include "enums.h"

static button_t *load_btn_texture(void)
{
    button_t *btn_texture = malloc(sizeof(button_t));

    btn_texture->base_text = sfTexture_createFromFile("assets/b.png", NULL);
    btn_texture->hover_text = sfTexture_createFromFile("assets/hover_button.png", NULL);
    btn_texture->click_text = sfTexture_createFromFile("assets/clicked_button.png", NULL);
    return btn_texture;
}    

earth_t *init_earth(void)
{
    earth_t *earth = malloc(sizeof(earth_t));

    earth->w = init_window();
    earth->sphere = init_sphere(&earth->w->size);
    earth->btn_textures = load_btn_texture();
    earth->buttons[RESET] = "reset";
    return earth;
}
