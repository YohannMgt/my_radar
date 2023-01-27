/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** timer
*/

#include "../include/my_prototypes.h"

void show_minutes(sfRenderWindow *window, game_t *game, sfText *text)
{
    if (game->my_timer->minutes < 10) {
        sfText_setString(text, "0");
        sfText_setPosition(text, (sfVector2f) {1739, 10});
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfText_setString(text, my_int_to_str(game->my_timer->minutes));
    if (game->my_timer->minutes >= 10)
        sfText_setPosition(text, (sfVector2f) {1740, 10});
    else
        sfText_setPosition(text, (sfVector2f) {1770, 10});
    sfRenderWindow_drawText(window, text, NULL);
}

void show_seconds(sfRenderWindow *window, game_t *game, sfText *text)
{
    if (game->my_timer->seconds < 10) {
        sfText_setString(text, "0");
        sfText_setPosition(text, (sfVector2f) {1809, 10});
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfText_setString(text, my_int_to_str(game->my_timer->seconds));
    if (game->my_timer->seconds >= 10)
        sfText_setPosition(text, (sfVector2f) {1810, 10});
    else
        sfText_setPosition(text, (sfVector2f) {1840, 10});
    sfRenderWindow_drawText(window, text, NULL);
}

void show_timer(sfRenderWindow *window, game_t *game)
{
    sfFont *font = sfFont_createFromFile(DIGITAL_7);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setFillColor(text, sfBlack);
    show_minutes(window, game, text);
    sfText_setString(text, ":");
    sfText_setPosition(text, (sfVector2f) {1800, 10});
    sfRenderWindow_drawText(window, text, NULL);
    show_seconds(window, game, text);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void get_timer(sfRenderWindow *window, game_t *game)
{
    sfTime elapsed = sfClock_getElapsedTime(game->global);

    game->my_timer->seconds = elapsed.microseconds / 1000000;
    game->my_timer->minutes = game->my_timer->seconds / 60;
    game->my_timer->seconds = game->my_timer->seconds % 60;
}
