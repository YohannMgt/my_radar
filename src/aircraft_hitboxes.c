/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** aircraft_hitboxes
*/

#include "../include/my_prototypes.h"

void render_hitboxes_aircrafts(game_t *game, sfRenderWindow *window,
aircraft_t *aircraft)
{
    if (aircraft->take_off == 1 && aircraft->land_in == 0 &&
    aircraft->destroyed == 0) {
        sfRectangleShape_move(aircraft->hitbox, aircraft->position);
        if (aircraft->in_tower_area == 0)
            aircraft->hitbox_color = sfYellow;
        if (aircraft->in_tower_area == 1)
            aircraft->hitbox_color = sfGreen;
        sfRectangleShape_setOutlineColor(aircraft->hitbox,
        aircraft->hitbox_color);
        sfRenderWindow_drawRectangleShape(window, aircraft->hitbox, NULL);
    }
}

void set_hitboxes_aircrafts(aircraft_t *aircraft)
{
    aircraft->hitbox_rect.left = aircraft->position.x;
    aircraft->hitbox_rect.top = aircraft->position.y;
    sfRectangleShape_setOrigin(aircraft->hitbox,
    (sfVector2f) {PLANE_WIDTH / 2, PLANE_HEIGHT / 2});
    sfRectangleShape_setPosition(aircraft->hitbox, aircraft->hitbox_position);
    sfRectangleShape_setFillColor(aircraft->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(aircraft->hitbox,
    aircraft->hitbox_thickness);
    sfRectangleShape_setSize(aircraft->hitbox, aircraft->hitbox_size);
}
