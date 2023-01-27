/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** clean
*/

#include "../include/my_prototypes.h"

void destroy_game(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i < game->nb_a; i++) {
        sfTexture_destroy(game->aircrafts[i]->texture);
        sfSprite_destroy(game->aircrafts[i]->sprite);
        sfRectangleShape_destroy(game->aircrafts[i]->hitbox);
    }
    for (int i = 0; i < game->nb_t; i++) {
        sfTexture_destroy(game->towers[i]->texture);
        sfSprite_destroy(game->towers[i]->sprite);
        sfCircleShape_destroy(game->towers[i]->area);
    }
    for (int i = 0; i < GRID; i++)
        sfRectangleShape_destroy(game->grid[i]->rectangle);
    sfTexture_destroy(game->map_texture);
    sfSprite_destroy(game->map_sprite);
    sfTexture_destroy(game->menu_texture);
    sfSprite_destroy(game->menu_sprite);
    sfClock_destroy(game->global);
    sfClock_destroy(game->movement);
    sfClock_destroy(game->fps_clock);
    sfRenderWindow_destroy(window);
}

void free_game(game_t *game)
{
    for (int i = 0; i < game->nb_t; i++)
        free(game->towers[i]);
    free(game->towers);
    for (int i = 0; i < game->nb_a; i++)
        free(game->aircrafts[i]);
    free(game->aircrafts);
    for (int i = 0; i < GRID; i++)
        free(game->grid[i]);
    free(game->grid);
    free(game->my_timer);
    free(game);
}
