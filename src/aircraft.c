/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** aircraft
*/

#include "../include/my_prototypes.h"

void check_take_off_land_in(game_t *game, aircraft_t *aircraft)
{
    float time = sfClock_getElapsedTime(game->global).microseconds / 1000000.0;

    if (time >= aircraft->delay)
        aircraft->take_off = 1;
    if (check_landing(aircraft) != 0)
        aircraft->land_in = 1;
}

int check_landing(aircraft_t *aircraft)
{
    sfVector2f position = aircraft->position;
    sfVector2f arrival = aircraft->arrival;

    switch (aircraft->pos_case) {
        case 1: return (position.x > arrival.x && position.y > arrival.y);
        case 2: return (position.x < arrival.x && position.y > arrival.y);
        case 3: return (position.x < arrival.x && position.y < arrival.y);
        case 4: return (position.x > arrival.x && position.y < arrival.y);
        case 5: return (position.x >= arrival.x);
        case 6: return (position.y >= arrival.y);
        case 7: return (position.x <= arrival.x);
        case 8: return (position.y <= arrival.y);
    }
    return (1);
}

void move_aircrafts(game_t *game, aircraft_t *aircraft)
{
    if (aircraft->take_off == 1 && aircraft->land_in == 0 &&
    aircraft->destroyed == 0) {
        sfSprite_move(aircraft->sprite, aircraft->direction);
        aircraft->position.x += aircraft->direction.x;
        aircraft->position.y += aircraft->direction.y;
        aircraft->hitbox_rect.left += aircraft->direction.x;
        aircraft->hitbox_rect.top += aircraft->direction.y;
    }
}

void render_aircrafts(game_t *game, sfRenderWindow *window,
aircraft_t *aircraft)
{
    if (aircraft->take_off == 1 && aircraft->land_in == 0 &&
    aircraft->destroyed == 0) {
        sfRenderWindow_drawSprite(window, aircraft->sprite, NULL);
    }
}

void draw_aircrafts(sfRenderWindow *window, game_t *game)
{
    aircraft_t **aircrafts = game->aircrafts;

    game->nb_a_landed_in = 0;
    for (int i = 0; i < game->nb_a; i++) {
        check_take_off_land_in(game, aircrafts[i]);
        game->nb_a_landed_in += aircrafts[i]->land_in;
        in_tower_area(game, aircrafts[i]);
        if (aircrafts[i]->destroyed == 0 && aircrafts[i]->in_tower_area == 0)
            aircraft_collision(game, aircrafts[i], i);
        set_hitboxes_aircrafts(aircrafts[i]);
        move_aircrafts(game, aircrafts[i]);
        if (game->key_s)
            render_aircrafts(game, window, aircrafts[i]);
        if (game->key_l)
            render_hitboxes_aircrafts(game, window, aircrafts[i]);
    }
    if (game->nb_a == game->nb_a_destroyed + game->nb_a_landed_in)
        game->end = 1;
}
