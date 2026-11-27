/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Event reset button
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>
#include <stdbool.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"

static void reset_point(point_t *point)
{
    float r = point->spherical.x;
    float theta = point->spherical.y;
    float phi = point->spherical.z;
    
    point->cartesian = (sfVector3f){
        r * sin(theta * M_PI / 180) * cos(phi * M_PI / 180),
        r * sin(theta * M_PI / 180) * sin(phi * M_PI / 180),
        r * cos(theta * M_PI / 180)
    };
}

void btn_reset(earth_t *earth)
{
    earth->w->set_view.x = 0.0;
    earth->w->set_view.y = 0.0;
    earth->sphere->zoom = 200;
    for (int i = 0; i < 614; i++) {
        earth->sphere->points[i]->spherical.x = earth->sphere->r;
        reset_point(earth->sphere->points[i]);
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            earth->sphere->rotation[i][j] = i == j ? 1.0 : 0.0;
    apply_rotation(earth->sphere);
    resize_window(earth->w, earth->sphere);
    set_pos_btn(earth->buttons, &earth->w->set_view);
}
