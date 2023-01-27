/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** my_prototypes
*/

#ifndef MY_PROTOTYPES_H_
    #define MY_PROTOTYPES_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include "my_structs.h"
    #include "my_macros.h"

    int my_getnbr(char const *str);
    char *my_int_to_str(int nb);
    int rev(int nb);
    int nbsize(int nb);
    int my_putchar(char c);
    int my_putstr(char const *str);
    char *my_strappend(char *dest, char src);
    char *my_strcat(char *dest, char const *src);
    int my_strlen(char const *str);

    int pos_case(sfVector2f departure, sfVector2f arrival);
    sfRectangleShape *aircraft_hitbox(aircraft_t *aircraft);
    sfSprite *aircraft_sprite(aircraft_t *aircraft);
    void set_aircraft(aircraft_t *aircraft, game_t *game);
    void init_aircraft(game_t *game, char *line);
    sfVector2f direction(aircraft_t *aircraft);
    int rotation(aircraft_t *aircraft);
    int nb_aircrafts(FILE *fp, char *line, size_t len);
    char *add_to_tab(char *line, int i);
    char **parser(char *line);
    int read_file(game_t *game, FILE *fp, char *line, size_t len);
    void init_fields(game_t *game, char *line, size_t len, char *filepath);
    game_t *init_game(char *filepath);
    sfSprite *map_sprite(game_t *game);
    void init_map(game_t *game);
    sfSprite *menu_sprite(game_t *game);
    void init_menu(game_t *game);
    void menu(sfRenderWindow *window, game_t *game, sfEvent event);
    sfCircleShape *tower_area(tower_t *tower);
    sfSprite *tower_sprite(tower_t *tower);
    void init_tower(game_t *game, char *line);
    int nb_towers(FILE *fp, char *line, size_t len);

    void destroy_aircrafts(game_t *game, aircraft_t *aircraft_a,
    aircraft_t *aircraft_b);
    void aircraft_collision(game_t *game, aircraft_t *aircraft, int i);
    void render_hitboxes_aircrafts(game_t *game, sfRenderWindow *window,
    aircraft_t *aircraft);
    void set_hitboxes_aircrafts(aircraft_t *aircraft);
    int collision_top_left(game_t *game, aircraft_t *aircraft, int i);
    int collision_top_right(game_t *game, aircraft_t *aircraft, int i);
    int collision_bottom_left(game_t *game, aircraft_t *aircraft, int i);
    int collision_bottom_right(game_t *game, aircraft_t *aircraft, int i);
    void in_tower_area(game_t *game, aircraft_t *aircraft);
    void check_take_off_land_in(game_t *game, aircraft_t *aircraft);
    int check_landing(aircraft_t *aircraft);
    void move_aircrafts(game_t *game, aircraft_t *aircraft);
    void render_aircrafts(game_t *game, sfRenderWindow *window,
    aircraft_t *aircraft);
    void draw_aircrafts(sfRenderWindow *window, game_t *game);
    void destroy_game(game_t *game, sfRenderWindow *window);
    void free_game(game_t *game);
    void close_window(sfRenderWindow *window);
    void manage_keys(game_t *game, sfRenderWindow *window, sfKeyCode code);
    void analyse_events(sfRenderWindow *window, game_t *game, sfEvent event);
    void show_fps(sfRenderWindow *window, game_t *game);
    void get_fps(sfRenderWindow *window, game_t *game);
    void start_game(sfRenderWindow *window, game_t *game, float seconds);
    void game_steps(game_t *game, sfRenderWindow *window, float seconds,
    sfEvent event);
    void game_loop(sfRenderWindow *window, game_t *game, sfEvent event);
    int display_usage(void);
    int good_arguments(int ac, char **av);
    int bad_arguments(void);
    int main(int ac, char **av);
    void display_grid(sfRenderWindow *window, game_t *game);
    void set_grid(game_t *game, int i);
    void init_grid(game_t *game);
    void show_minutes(sfRenderWindow *window, game_t *game, sfText *text);
    void show_seconds(sfRenderWindow *window, game_t *game, sfText *text);
    void show_timer(sfRenderWindow *window, game_t *game);
    void get_timer(sfRenderWindow *window, game_t *game);
    void render_area_towers(sfRenderWindow *window, game_t *game, int i);
    void render_towers(sfRenderWindow *window, game_t *game, int i);
    void draw_towers(sfRenderWindow *window, game_t *game);

#endif /* !MY_PROTOTYPES_H_ */
