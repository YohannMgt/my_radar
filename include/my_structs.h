/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "my_prototypes.h"

    typedef struct aircraft {
        sfSprite *sprite;
        sfTexture *texture;
        sfRectangleShape *hitbox;
        sfColor hitbox_color;
        float hitbox_thickness;
        sfVector2f hitbox_position;
        sfVector2f hitbox_size;
        sfIntRect hitbox_rect;
        sfVector2f departure;
        sfVector2f direction;
        sfVector2f position;
        sfVector2f arrival;
        int pos_case;
        int rotation;
        int speed;
        int delay;
        int take_off;
        int in_tower_area;
        int land_in;
        int destroyed;
    } aircraft_t;

    typedef struct tower {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f position;
        sfCircleShape *area;
        sfColor area_color;
        float area_thickness;
        sfVector2f area_position;
        int radius;
    } tower_t;

    typedef struct grid_base {
        sfRectangleShape *rectangle;
        sfColor fill_color;
        sfColor outline_color;
        float outline_thickness;
        sfVector2f size;
        sfVector2f position;
    } grid_base_t;

    typedef struct my_timer {
        int seconds;
        int minutes;
    } my_timer_t;

    typedef struct game {
        aircraft_t **aircrafts;
        tower_t **towers;
        grid_base_t **grid;
        my_timer_t *my_timer;
        sfSprite *map_sprite;
        sfTexture *map_texture;
        sfSprite *menu_sprite;
        sfTexture *menu_texture;
        sfClock *global;
        sfClock *movement;
        sfClock *fps_clock;
        int nb_t;
        int nb_a;
        int nb_a_landed_in;
        int nb_a_destroyed;
        int start;
        int end;
        int fps;
        int key_l;
        int key_s;
        int key_f;
        int key_g;
        int key_t;
    } game_t;

#endif /* !GAME_H_ */
