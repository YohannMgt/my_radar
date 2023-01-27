/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** my_macros
*/

#ifndef MY_MACROS_H_
    #define MY_MACROS_H_

    #define WINDOW_WIDTH        1920
    #define WINDOW_HEIGHT       1080
    #define PLANE_WIDTH         20
    #define PLANE_HEIGHT        20
    #define TOWER_WIDTH         60
    #define TOWER_HEIGHT        60
    #define GRID                100
    #define PI                  3.14159265359

    #define IMAGES              "assets/images/"
    #define FONTS               "assets/fonts/"

    #define MAP                 IMAGES "map.png"
    #define MAP_BLUR            IMAGES "map_blur.png"
    #define PLANE               IMAGES "plane.png"
    #define TOWER               IMAGES "tower.png"
    #define QUICKSAND_BOLD      FONTS  "quicksand/Quicksand-Bold.otf"
    #define QUICKSAND_REGULAR   FONTS  "quicksand/Quicksand-Regular.otf"
    #define DIGITAL_7           FONTS  "digital-7/digital-7.ttf"

    #define MIN(a, b)            (((a) < (b)) ? (a) : (b))
    #define MAX(a, b)            (((a) > (b)) ? (a) : (b))

    #define MAX_WINDOW          MAX(WINDOW_WIDTH, WINDOW_HEIGHT)

    #define RADIUS(x)           ((x) * MAX_WINDOW / 100)

#endif /* !MY_MACROS_H_ */
