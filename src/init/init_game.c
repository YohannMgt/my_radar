/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_game
*/

#include "../../include/my_prototypes.h"

char *add_to_tab(char *line, int i)
{
    int j = i;
    char *res = malloc(sizeof(char) * 5);

    res[0] = '\0';
    while (line[j] != ' ' && line[j] != '\n') {
        my_strappend(res, line[j]);
        j++;
    }
    return (res);
}

char **parser(char *line)
{
    char **information = malloc(sizeof(char *) * my_strlen(line));
    int i = 1;
    int j = 0;

    while (line[i] != '\0') {
        if (line[i - 1] == ' ' && line[i] != ' ') {
            information[j] = add_to_tab(line, i);
            j++;
        }
        i++;
    }
    return (information);
}

int read_file(game_t *game, FILE *fp, char *line, size_t len)
{
    while (getline(&line, &len, fp) != -1) {
        if (line[0] != 'A' && line[0] != 'T') {
            my_putstr("Error : invalid script\n");
            return (1);
        }
        if (line[0] == 'A')
            init_aircraft(game, line);
        if (line[0] == 'T')
            init_tower(game, line);
    }
    if (line)
        free(line);
}

void init_fields(game_t *game, char *line, size_t len, char *filepath)
{
    FILE *fp = fopen(filepath, "r");

    game->aircrafts = malloc(sizeof(aircraft_t) *
    (nb_aircrafts(fp, line, len) + 1));
    fp = fopen(filepath, "r");
    game->towers = malloc(sizeof(tower_t) * (nb_towers(fp, line, len) + 1));
    game->grid = malloc(sizeof(grid_base_t) * GRID);
    game->my_timer = malloc(sizeof(my_timer_t));
    game->nb_a = 0;
    game->nb_t = 0;
    game->start = 0;
    game->end = 0;
    game->fps = 0;
    game->key_l = 0;
    game->key_s = 1;
    game->key_f = 0;
    game->key_g = 0;
    game->key_t = 1;
}

game_t *init_game(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL) {
        my_putstr("Error : file doesn't exist\n");
        return (NULL);
    }
    init_fields(game, line, len, filepath);
    fp = fopen(filepath, "r");
    if (read_file(game, fp, line, len) == 1)
        return (NULL);
    init_menu(game);
    init_map(game);
    init_grid(game);
    return (game);
}
