/*
** DUBOIS PROJECT, 2026
** myearth3d
** File description:
** Enums definition
*/

#ifndef ENUMS_H_
#define ENUMS_H_

typedef enum cursor_type_s {
    HAND,
    ARROW,
    TYPE_COUNT
} cursor_type_t;

typedef enum button_click_s {
    RESET,
    BTN_COUNT
} button_click_t;

typedef enum mouse_pressed_s {
    NONE,
    MAP,
    POINT
} mouse_pressed_t;

typedef enum type_square_s {
    TRIANGLE,
    SQUARE
} type_square_t;

#endif
