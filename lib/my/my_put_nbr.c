/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** display the number given as a parameter
*/

void my_putchar(char c);

int rev(int nb)
{
    int a = 0;
    int b = 0;

    while (nb > 0) {
        a = nb % 10;
        nb = nb / 10;
        b *= 10;
        b += a;
    }
    return (b);
}

int nbsize(int nb)
{
    int i = 0;

    for (i; nb > 0; i++) {
        nb = nb / 10;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar(48);
        return (0);
    } else {
        int reverse_nb = 0;
        if (nb < 0) {
            nb = -nb;
            my_putchar('-');
        }
        reverse_nb = rev(nb);
        int size = nbsize(nb);

        for (int i = 0; i < size; i++) {
            my_putchar((reverse_nb % 10) + 48);
            reverse_nb = reverse_nb / 10;
        }
    }
}
