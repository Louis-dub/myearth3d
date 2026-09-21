/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Calculate new rotation
 */

#include <math.h>
#include <string.h>

#include "my_struct.h"

static void get_matrix_one_rotation(float matrix[3][3], sfVector3f *dir, float d)
{
    float x = dir->x;
    float y = dir->y;
    float z = dir->z;

    matrix[0][0] = x * x + (1 - x * x) * cos(d);
    matrix[0][1] = x * y * (1 - cos(d)) - z * sin(d);
    matrix[0][2] = x * z * (1 - cos(d)) + y * sin(d);
    matrix[1][0] = x * y * (1 - cos(d)) + z * sin(d);
    matrix[1][1] = y * y + (1 - y * y) * cos(d);
    matrix[1][2] = y * z * (1 - cos(d)) - x * sin(d);
    matrix[2][0] = x * z * (1 - cos(d)) - y * sin(d);
    matrix[2][1] = y * z * (1 - cos(d)) + x * sin(d);
    matrix[2][2] = z * z + (1 - z * z) * cos(d);
}

static void get_matrix_double_rotation(float m1[3][3], float m2[3][3], float mr[3][3])
{
    mr[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0];
    mr[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1];
    mr[0][2] = m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2];
    mr[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0];
    mr[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1];
    mr[1][2] = m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2];
    mr[2][0] = m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0];
    mr[2][1] = m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1];
    mr[2][2] = m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2];
}

void apply_rotation(sphere_t *sphere)
{
    float m1[3][3];
    float m2[3][3];
    float mr[3][3];
    float mfinal[3][3];
    float d1 = sphere->angles.x * M_PI / 180.0;
    float d2 = sphere->angles.y * M_PI / 180.0;

    get_matrix_one_rotation(m1, &sphere->axes[0], d1);
    get_matrix_one_rotation(m2, &sphere->axes[1], d2);
    get_matrix_double_rotation(m1, m2, mr);
    get_matrix_double_rotation(mr, sphere->rotation, mfinal);
    memcpy(sphere->rotation, mfinal, sizeof(mfinal));
    sphere->angles.x = 0.0;
    sphere->angles.y = 0.0;
}
