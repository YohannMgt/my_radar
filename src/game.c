/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** game
*/

#include "../include/my_prototypes.h"

void start_game(sfRenderWindow *window, game_t *game, float seconds)
{
    if (seconds > 0.005) {
        sfClock_restart(game->movement);
        sfRenderWindow_drawSprite(window, game->map_sprite, NULL);
        draw_towers(window, game);
        draw_aircrafts(window, game);
        get_fps(window, game);
        get_timer(window, game);
        display_grid(window, game);
        if (game->key_f == 1)
            show_fps(window, game);
        if (game->key_t == 1)
            show_timer(window, game);
    }
}

void game_steps(game_t *game, sfRenderWindow *window, float seconds,
sfEvent event)
{
    if (game->start == 1)
        start_game(window, game, seconds);
    else
        menu(window, game, event);
    if (game->end == 1)
        close_window(window);
}

void game_loop(sfRenderWindow *window, game_t *game, sfEvent event)
{
    sfTime time;
    float seconds = 1.0;
    sfVector2i window_pos = {0, 0};

    sfRenderWindow_setPosition(window, window_pos);
    sfRenderWindow_setFramerateLimit(window, 60);
    game->global = sfClock_create();
    game->my_timer->minutes = 0;
    game->my_timer->seconds = 0;
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, game, event);
        seconds = time.microseconds / 1000000.0;
        time = sfClock_getElapsedTime(game->movement);
        game_steps(game, window, seconds, event);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
}
