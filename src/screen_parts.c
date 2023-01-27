/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-yohann.mangenot
** File description:
** screen_parts
*/

#include "../include/my_prototypes.h"

void display_grid(sfRenderWindow *window, game_t *game)
{
    if (game->key_g == 1) {
        for (int i = 0; i < GRID; i++) {
            sfRenderWindow_drawRectangleShape
            (window, game->grid[i]->rectangle, NULL);
        }
    }
}

void set_grid(game_t *game, int i)
{
    grid_base_t *grid = game->grid[i];

    sfRectangleShape_setFillColor(grid->rectangle, grid->fill_color);
    sfRectangleShape_setOutlineColor(grid->rectangle, grid->outline_color);
    sfRectangleShape_setOutlineThickness
    (grid->rectangle, grid->outline_thickness);
    sfRectangleShape_setSize(grid->rectangle, grid->size);
    sfRectangleShape_setPosition(grid->rectangle, grid->position);
}

void init_grid(game_t *game)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < GRID; i++) {
        game->grid[i] = malloc(sizeof(grid_base_t));
        game->grid[i]->rectangle = sfRectangleShape_create();
        game->grid[i]->fill_color = sfTransparent;
        game->grid[i]->outline_color = sfRed;
        game->grid[i]->outline_thickness = 1;
        game->grid[i]->size =
        (sfVector2f) {WINDOW_WIDTH / sqrt(GRID), WINDOW_HEIGHT / sqrt(GRID)};
        game->grid[i]->position = (sfVector2f) {j, k};
        j += WINDOW_WIDTH / sqrt(GRID);
        if (i % (int)(sqrt(GRID)) == sqrt(GRID) - 1) {
            k += WINDOW_HEIGHT / sqrt(GRID);
            j = 0;
        }
        set_grid(game, i);
    }
}
