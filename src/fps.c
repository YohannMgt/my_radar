/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** fps
*/

#include "../include/my_prototypes.h"

void show_fps(sfRenderWindow *window, game_t *game)
{
    sfFont *font = sfFont_createFromFile(QUICKSAND_REGULAR);
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfGreen);
    sfText_setString(text, my_int_to_str(game->fps));
    sfText_setPosition(text, (sfVector2f) {10, 10});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setString(text, "FPS");
    sfText_setPosition(text, (sfVector2f) {60, 10});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void get_fps(sfRenderWindow *window, game_t *game)
{
    static int first = 1;
    static int fps = 0;

    if (first == 1) {
        game->fps_clock = sfClock_create();
        first = 0;
    }
    if (sfClock_getElapsedTime(game->fps_clock).microseconds / 1000000.0 >= 1) {
        game->fps = fps;
        fps = 0;
        sfClock_restart(game->fps_clock);
    } else
        fps++;
}
