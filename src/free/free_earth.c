/*
** DUBOIS PRJECT, 2026
** myearth3d
** File decription:
** free struct all datas
*/

#include <CSFML/Graphics.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"

void free_earth(earth_t *earth)
{
    free_window(earth->w);
    free_sphere(earth->sphere);
    free_btn_text(earth->btn_textures);
    free_buttons(earth->buttons);
    sfFont_destroy(earth->font);
    free(earth);
}
