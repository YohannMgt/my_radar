/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_map
*/

#include "../../include/my_prototypes.h"

sfSprite *map_sprite(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    game->map_texture = sfTexture_createFromFile(MAP, NULL);;
    sfSprite_setTexture(sprite, game->map_texture, sfTrue);
    return (sprite);
}

void init_map(game_t *game)
{
    game->map_sprite = map_sprite(game);
}
