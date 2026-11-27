/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Events for menu buttons
*/

#include <CSFML/Graphics.h>
#include <CSFML/System.h>
#include <CSFML/Window.h>
#include <stdbool.h>

#include "my_functions.h"
#include "my_struct.h"
#include "enums.h"

void btn_create_map(earth_t *earth)
{
    earth->screen = EDIT;
}

void btn_go_menu(earth_t *earth)
{
    btn_reset(earth);
    earth->screen = MENU;
}
