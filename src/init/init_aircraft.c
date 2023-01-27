/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_aircraft
*/

#include "../../include/my_prototypes.h"

int pos_case(sfVector2f departure, sfVector2f arrival)
{
    if (arrival.x > departure.x && arrival.y > departure.y)
        return (1);
    if (arrival.x < departure.x && arrival.y > departure.y)
        return (2);
    if (arrival.x < departure.x && arrival.y < departure.y)
        return (3);
    if (arrival.x > departure.x && arrival.y < departure.y)
        return (4);
    if (arrival.x > departure.x && arrival.y == departure.y)
        return (5);
    if (arrival.x == departure.x && arrival.y > departure.y)
        return (6);
    if (arrival.x < departure.x && arrival.y == departure.y)
        return (7);
    if (arrival.x == departure.x && arrival.y < departure.y)
        return (8);
}

sfRectangleShape *aircraft_hitbox(aircraft_t *aircraft)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f hitbox_position = {0, 0};
    sfVector2f hitbox_size = {PLANE_WIDTH, PLANE_HEIGHT};

    aircraft->hitbox_color = sfTransparent;
    aircraft->hitbox_thickness = 2;
    aircraft->hitbox_position = hitbox_position;
    aircraft->hitbox_size = hitbox_size;
    aircraft->hitbox_rect.top = aircraft->hitbox_position.y;
    aircraft->hitbox_rect.left = aircraft->hitbox_position.x;
    aircraft->hitbox_rect.height = PLANE_HEIGHT;
    aircraft->hitbox_rect.width = PLANE_WIDTH;
    return (hitbox);
}

sfSprite *aircraft_sprite(aircraft_t *aircraft)
{
    sfSprite *sprite = sfSprite_create();

    aircraft->texture = sfTexture_createFromFile(PLANE, NULL);
    sfSprite_setTexture(sprite, aircraft->texture, sfTrue);
    sfSprite_setPosition(sprite, aircraft->departure);
    return (sprite);
}

void set_aircraft(aircraft_t *aircraft, game_t *game)
{
    sfSprite_setOrigin(aircraft->sprite,
    (sfVector2f) {PLANE_WIDTH / 2, PLANE_HEIGHT / 2});
    sfSprite_setRotation(aircraft->sprite, aircraft->rotation);
    aircraft->take_off = 0;
    aircraft->land_in = 0;
    aircraft->in_tower_area = 0;
    aircraft->destroyed = 0;
    game->nb_a_landed_in = 0;
    game->nb_a_destroyed = 0;
}

void init_aircraft(game_t *game, char *line)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    game->aircrafts[game->nb_a] = aircraft;
    aircraft->departure.x = my_getnbr(parser(line)[0]);
    aircraft->departure.y = my_getnbr(parser(line)[1]);
    aircraft->arrival.x = my_getnbr(parser(line)[2]);
    aircraft->arrival.y = my_getnbr(parser(line)[3]);
    aircraft->speed = my_getnbr(parser(line)[4]);
    aircraft->delay = my_getnbr(parser(line)[5]);
    aircraft->position.x = aircraft->departure.x;
    aircraft->position.y = aircraft->departure.y;
    aircraft->direction = direction(aircraft);
    aircraft->sprite = aircraft_sprite(aircraft);
    aircraft->hitbox = aircraft_hitbox(aircraft);
    aircraft->pos_case = pos_case(aircraft->departure, aircraft->arrival);
    aircraft->rotation = rotation(aircraft);
    set_aircraft(aircraft, game);
    game->nb_a += 1;
}
