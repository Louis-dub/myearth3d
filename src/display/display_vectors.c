/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Display direction vectors
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <math.h>

#include "my_functions.h"
#include "my_struct.h"

static void display_vectors(sfRenderWindow *w, sfVector2i *p, sfVector2f *o, sfColor color)
{
    sfVertexArray *vector = sfVertexArray_create();
    sfVertex p1 = {(sfVector2f){p->x, p->y}, color};
    sfVertex p2 = {*o, color};

    sfVertexArray_append(vector, p1);
    sfVertexArray_append(vector, p2);
    sfVertexArray_setPrimitiveType(vector, sfLineStrip);
    sfRenderWindow_drawVertexArray(w, vector, NULL);
    sfVertexArray_destroy(vector);
}

static sfVector2i *findx(point_t **points)
{
    for (int i = 0; i < 614; i++) {
        if (fabs(points[i]->cartesian.x) < 1e-6 && fabs(points[i]->cartesian.z) < 1e-6) {
            return &points[i]->screen;
        }
    }
    return NULL;
}

static sfVector2i *findy(point_t **points)
{
    for (int i = 0; i < 614; i++) {
        if (fabs(points[i]->cartesian.y) < 1e-6 && fabs(points[i]->cartesian.z) < 1e-6) {
            return &points[i]->screen;
        }
    }
    return NULL;
}

void display_xyz(sfRenderWindow *w, sphere_t *sphere, sfVector2u size)
{
    sfVector2f o = {size.x / 2.0, size.y / 2.0};
    sfVector2i axe0 = project_iso_point(&sphere->axes[0], sphere, &size);
    sfVector2i axe1 = project_iso_point(&sphere->axes[1], sphere, &size);

    display_vectors(w, &sphere->points[0]->screen, &o, sfRed);
    display_vectors(w, findx(sphere->points), &o, sfBlue);
    display_vectors(w, findy(sphere->points), &o, sfGreen);
    //display_vectors(w, &axe0, &o, sfYellow);
    //display_vectors(w, &axe1, &o, sfMagenta);
}
