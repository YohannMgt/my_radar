/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** aircraft_collisions
*/

#include "../include/my_prototypes.h"

void destroy_aircrafts(game_t *game, aircraft_t *aircraft_a,
aircraft_t *aircraft_b)
{
    if (sfIntRect_intersects(&aircraft_a->hitbox_rect,
    &aircraft_b->hitbox_rect, NULL)) {
        aircraft_a->destroyed = 1;
        aircraft_b->destroyed = 1;
        game->nb_a_destroyed += 2;
    }
}

void aircraft_collision(game_t *game, aircraft_t *aircraft_a, int i)
{
    aircraft_t *aircraft_b;

    for (int j = 0; j < game->nb_a; j++) {
        aircraft_b = game->aircrafts[j];
        if (i != j && aircraft_b->destroyed == 0 &&
        aircraft_b->in_tower_area == 0 && aircraft_a->take_off == 1 &&
        aircraft_b->take_off == 1 && aircraft_a->land_in == 0 &&
        aircraft_b->land_in == 0)
            destroy_aircrafts(game, aircraft_a, aircraft_b);
    }
}
