/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-yohann.mangenot
** File description:
** my_int_to_str
*/

#include "../../include/my_prototypes.h"

char *my_int_to_str(int nb)
{
    char *result = malloc(nbsize(nb));
    int reverse_nb = rev(nb);
    int size = nbsize(nb);

    result[0] = '\0';
    if (nb == 0)
        return ("0");
    for (int i = 0; i < size; i++) {
        my_strappend(result, (reverse_nb % 10) + 48);
        reverse_nb = reverse_nb / 10;
    }
    return (result);
}
