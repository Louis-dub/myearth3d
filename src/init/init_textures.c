/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Init map textures
 */

#include <CSFML/Graphics.h>
#include <CSFML/Graphics/Color.h>
#include <CSFML/System.h>
#include <math.h>
#include <stdint.h>

#include "my_struct.h"

sfTexture *create_texture(sfColor *color)
{
    sfImage *image = sfImage_create((sfVector2u){256, 256});
    sfTexture *texture;
    sfColor f_color;

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            f_color = sfColor_fromRGB(
                                      (uint8_t)fmax(0, fmin(255, (int)color->r + rand() % 21 - 10)),
                                      (uint8_t)fmax(0, fmin(255, (int)color->g + rand() % 21 - 10)),
                                      (uint8_t)fmax(0, fmin(255, (int)color->b + rand() % 21 - 10))
            );
            sfImage_setPixel(image, (sfVector2u){i, j}, f_color);
        }
    }
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}


void init_textures(sphere_t *sphere)
{
    sfColor colors[5] = {
      sfColor_fromRGB(30, 100, 200),
      sfColor_fromRGB(194, 178, 128),
      sfColor_fromRGB(34, 139, 34),
      sfColor_fromRGB(128, 128, 128),
      sfColor_fromRGB(240, 230, 255)
    };

    for (int i = 0; i < 5; i++)
        sphere->textures[i] = create_texture(&colors[i]);
}
