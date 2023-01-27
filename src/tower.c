/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** tower
*/

#include "../include/my_prototypes.h"

void render_area_towers(sfRenderWindow *window, game_t *game, int i)
{
    sfRenderWindow_drawCircleShape(window, game->towers[i]->area, NULL);
}

void render_towers(sfRenderWindow *window, game_t *game, int i)
{
    sfRenderWindow_drawSprite(window, game->towers[i]->sprite, NULL);
}

void draw_towers(sfRenderWindow *window, game_t *game)
{
    tower_t **towers = game->towers;

    for (int i = 0; i < game->nb_t; i++) {
        sfSprite_setPosition(towers[i]->sprite, towers[i]->position);
        sfCircleShape_setOrigin(game->towers[i]->area, (sfVector2f)
        {RADIUS(towers[i]->radius), RADIUS(towers[i]->radius)});
        sfCircleShape_setPosition(towers[i]->area, towers[i]->area_position);
        sfCircleShape_setRadius(towers[i]->area, RADIUS(towers[i]->radius));
        sfCircleShape_setFillColor(towers[i]->area, sfTransparent);
        sfCircleShape_setOutlineColor(towers[i]->area, towers[i]->area_color);
        sfCircleShape_setOutlineThickness(towers[i]->area,
        towers[i]->area_thickness);
        if (game->key_s == 1)
            render_towers(window, game, i);
        if (game->key_l == 1)
            render_area_towers(window, game, i);
    }
}
