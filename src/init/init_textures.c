/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init map textures
 */

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <math.h>

sfTexture *create_texture(sfColor *color)
{
    sfImage *image = sfImage_create(256, 256);
    sfTexture *texture;
    sfColor f_color;

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            f_color = sfColor_fromRGB(
                fmax(0, fmin(255, (int)color->r + rand() % 21 - 10)),
                fmax(0, fmin(255, (int)color->g + rand() % 21 - 10)),
                fmax(0, fmin(255, (int)color->b + rand() % 21 - 10))
            );
            sfImage_setPixel(image, (sfVector2u){i, j}, f_color);
        }
    }
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}


void init_textures(void)
{
}
