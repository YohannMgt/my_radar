/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** main
*/

#include "../include/my_prototypes.h"

int display_usage(void)
{
    int fd;
    char buffer[20000];

    fd = open("README.txt", O_RDONLY);
    read(fd, buffer, 19999);
    my_putstr(buffer);
    close(fd);
    return (0);
}

int good_arguments(int ac, char **av)
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    game_t *game = init_game(av[1]);

    if (av[1][0] == '-' && av[1][1] == 'h') {
        return (display_usage());
    } else {
        if (game == NULL)
            return (84);
        window = sfRenderWindow_create(video_mode, "My Radar", sfClose, NULL);
        game->movement = sfClock_create();
        game_loop(window, game, event);
        destroy_game(game, window);
        free_game(game);
    }
    return (0);
}

int bad_arguments(void)
{
    my_putstr("./my_radar: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return (84);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return (bad_arguments());
    if (ac == 2)
        return (good_arguments(ac, av));
    if (good_arguments(ac, av) == 84)
        return (84);
    else
        return (84);
}
