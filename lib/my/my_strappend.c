/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-yohann.mangenot
** File description:
** my_strappend
*/

int my_strlen(char const *str);

char *my_strappend(char *dest, char src)
{
    int i = my_strlen(dest);
    dest[i] = src;
    dest[i + 1] = '\0';
    return (dest);
}
