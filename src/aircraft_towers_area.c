/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** aircraft_towers_area
*/

#include "../include/my_prototypes.h"

int collision_top_left(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x - PLANE_WIDTH / 2;
    int ry = aircraft->position.y - PLANE_HEIGHT / 2;
    int top_left = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (top_left);
}

int collision_top_right(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x + PLANE_WIDTH / 2;
    int ry = aircraft->position.y - PLANE_HEIGHT / 2;
    int top_right = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (top_right);
}

int collision_bottom_left(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x - PLANE_WIDTH / 2;
    int ry = aircraft->position.y + PLANE_HEIGHT / 2;
    int bottom_left = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (bottom_left);
}

int collision_bottom_right(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x + PLANE_WIDTH / 2;
    int ry = aircraft->position.y + PLANE_HEIGHT / 2;
    int bottom_right = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (bottom_right);
}

void in_tower_area(game_t *game, aircraft_t *aircraft)
{
    int top_left;
    int top_right;
    int bottom_left;
    int bottom_right;
    int radius;

    for (int i = 0; i < game->nb_t; i++) {
        radius = RADIUS(game->towers[i]->radius);
        top_left = collision_top_left(game, aircraft, i);
        top_right = collision_top_right(game, aircraft, i);
        bottom_left = collision_bottom_left(game, aircraft, i);
        bottom_right = collision_bottom_right(game, aircraft, i);
        if (top_left <= radius || top_right <= radius ||
        bottom_left <= radius || bottom_right <= radius) {
            aircraft->in_tower_area = 1;
            return;
        }
        aircraft->in_tower_area = 0;
    }
}
