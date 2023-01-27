/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count and return number of characters found in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
