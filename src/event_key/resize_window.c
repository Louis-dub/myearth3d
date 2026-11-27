/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Resize window and set new view
*/

#include <CSFML/Graphics.h>
#include <CSFML/Graphics/Sprite.h>
#include <CSFML/Graphics/Text.h>
#include <CSFML/System/Vector2.h>

#include "my_functions.h"
#include "my_struct.h"

static void replace_btn(button_t *btn, sfVector2u *size)
{
    btn->position.x = (size->x / 2.0) - (btn->rect.size.x / 2.0);
    btn->position.y = (size->y * 0.25) - (btn->rect.size.y / 2.0);
    sfSprite_setPosition(btn->base, btn->position);
    sfSprite_setPosition(btn->hover, btn->position);
    sfSprite_setPosition(btn->click, btn->position);
    sfText_setPosition(btn->text, (sfVector2f){
        btn->position.x + btn->rect.size.x / 2.0,
        btn->position.y + btn->rect.size.y / 2.0 - 5
    });
}

void replace_menu_element(menu_t *menu, sfVector2u *size)
{
    sfText_setPosition(menu->title, (sfVector2f){
        size->x / 2.0,
        size->y * 0.1
    });
    replace_btn(menu->btn_create, size);
}

void resize_window(window_t *w, sphere_t *sphere)
{
    w->size = sfRenderWindow_getSize(w->window);
    sfView_setCenter(w->view, (sfVector2f){
        (float){w->size.x / 2.0} + w->set_view.x,
        (float){w->size.y / 2.0} + w->set_view.y});
    sfView_setSize(w->view, (sfVector2f){(float){w->size.x}, (float){w->size.y}});
    sfRenderWindow_setView(w->window, w->view);
    recalculation(w, sphere);
}
