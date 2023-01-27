/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_tower
*/

#include "../../include/my_prototypes.h"

sfCircleShape *tower_area(tower_t *tower)
{
    sfCircleShape *area = sfCircleShape_create();
    sfVector2f area_position;
    sfVector2f tower_position = tower->position;

    area_position.x = tower_position.x;
    area_position.y = tower_position.y;
    tower->area_color = sfBlue;
    tower->area_thickness = 2;
    tower->area_position = area_position;
    return (area);
}

sfSprite *tower_sprite(tower_t *tower)
{
    sfSprite *sprite = sfSprite_create();

    tower->texture =
    sfTexture_createFromFile(TOWER, NULL);
    sfSprite_setTexture(sprite, tower->texture,
    sfTrue);
    return (sprite);
}

void init_tower(game_t *game, char *line)
{
    tower_t *tower = malloc(sizeof(tower_t));

    game->towers[game->nb_t] = tower;
    tower->position.x = my_getnbr(parser(line)[0]);
    tower->position.y = my_getnbr(parser(line)[1]);
    tower->radius = my_getnbr(parser(line)[2]);
    tower->sprite = tower_sprite(tower);
    tower->area = tower_area(tower);
    sfSprite_setOrigin(tower->sprite,
    (sfVector2f) {TOWER_WIDTH / 2, TOWER_HEIGHT / 2});
    game->nb_t += 1;
}

int nb_towers(FILE *fp, char *line, size_t len)
{
    int nb_towers = 0;

    while (getline(&line, &len, fp) != -1) {
        if (line[0] == 'T')
            nb_towers++;
    }
    if (line)
        free(line);
    return (nb_towers);
}
