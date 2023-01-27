/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concatenate two strings
*/

int my_strlen (char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);

    while (i < my_strlen(src)) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
