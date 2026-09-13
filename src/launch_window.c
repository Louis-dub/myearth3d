/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** launch csfml window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdlib.h>

#include "my_functions.h"
#include "my_struct.h"


static sfCircleShape *create_circle(float scale_x)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 100.0);
    sfCircleShape_setOrigin(circle, (sfVector2f){100, 100});
    sfCircleShape_setPosition(circle, (sfVector2f){400, 300});
    sfCircleShape_setOutlineThickness(circle, 2);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    sfCircleShape_setScale(circle, (sfVector2f){scale_x, 1});
    return circle;
}

static sfCircleShape **create_circles()
{
    sfCircleShape **circles = malloc(sizeof(sfCircleShape*) * 4);
    float scale_x[4] = {1.0, 0.7, 0.5, 0.3};

    for (int i = 0; i < 4; i++)
        circles[i] = create_circle(scale_x[i]);
    return circles;
}

int launch_window(void)
{
    earth_t *earth = init_earth();
    sfCircleShape **circles = create_circles();

    while (sfRenderWindow_isOpen(earth->w->window)) {
        sfRenderWindow_clear(earth->w->window, (sfColor){120, 120, 120});
        while (sfRenderWindow_pollEvent(earth->w->window, &earth->w->event))
            analyse_event(earth, earth->w);
        //display_map(earth->w->window, earth->map);
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawCircleShape(earth->w->window, circles[i], NULL);
        sfRenderWindow_display(earth->w->window);
    }
    for (int i = 0; i < 4; i++)
        sfCircleShape_destroy(circles[i]);
    free(circles);
    free_earth(earth);
    return 0;
}
