/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** init_aircraft2
*/

#include "../../include/my_prototypes.h"

sfVector2f direction(aircraft_t *aircraft)
{
    sfVector2f direction_vector = {0, 0};
    sfVector2f displacement_vector = {0, 0};
    sfVector2f departure = aircraft->departure;
    sfVector2f arrival = aircraft->arrival;
    int speed = aircraft->speed;
    float hypothenus;

    direction_vector.x = arrival.x - departure.x;
    direction_vector.y = arrival.y - departure.y;
    hypothenus = sqrt((direction_vector.x * direction_vector.x) +
    (direction_vector.y * direction_vector.y));
    displacement_vector.x = direction_vector.x * speed / hypothenus / 40;
    displacement_vector.y = direction_vector.y * speed / hypothenus / 40;
    return (displacement_vector);
}

int rotation(aircraft_t *aircraft)
{
    float angle;

    angle = atan2(aircraft->direction.y, aircraft->direction.x);
    angle *= 180 / PI;
    if (angle < 0)
        angle += 360;
    return (angle);
}

int nb_aircrafts(FILE *fp, char *line, size_t len)
{
    int nb_aircrafts = 0;

    while (getline(&line, &len, fp) != -1) {
        if (line[0] == 'A')
            nb_aircrafts++;
    }
    if (line)
        free(line);
    return (nb_aircrafts);
}
