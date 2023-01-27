/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** events
*/

#include "../include/my_prototypes.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void manage_keys(game_t *game, sfRenderWindow *window, sfKeyCode code)
{
    if (code == sfKeyS)
        game->key_s = game->key_s == 1 ? 0 : 1;
    if (code == sfKeyL)
        game->key_l = game->key_l == 1 ? 0 : 1;
    if (code == sfKeyF)
        game->key_f = game->key_f == 1 ? 0 : 1;
    if (code == sfKeyG)
        game->key_g = game->key_g == 1 ? 0 : 1;
    if (code == sfKeyT)
        game->key_t = game->key_t == 1 ? 0 : 1;
    if (code == sfKeyQ)
        close_window(window);
}

void analyse_events(sfRenderWindow *window, game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if ((event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtKeyPressed && event.key.code != sfKeyQ)
        && game->start == 0) {
            game->start = 1;
            break;
        }
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtKeyPressed)
            manage_keys(game, window, event.key.code);
    }
}
