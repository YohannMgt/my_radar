/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_menu
*/

#include "../../include/my_prototypes.h"

sfSprite *menu_sprite(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    game->menu_texture = sfTexture_createFromFile(MAP_BLUR, NULL);
    sfSprite_setTexture(sprite, game->menu_texture, sfTrue);
    return (sprite);
}

void init_menu(game_t *game)
{
    game->menu_sprite = menu_sprite(game);
}

void menu(sfRenderWindow *window, game_t *game, sfEvent event)
{
    sfFont *font = sfFont_createFromFile(QUICKSAND_BOLD);
    sfVector2f position = {235, 450};
    sfText *text = sfText_create();

    sfText_setString(text,
    "Click on the screen or press any key to start simulation");
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfBlack);
    sfRenderWindow_drawSprite(window, game->menu_sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfClock_restart(game->global);
}
