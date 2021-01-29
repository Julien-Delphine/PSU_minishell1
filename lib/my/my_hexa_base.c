/*
** EPITECH PROJECT, 2019
** my_hexa_base
** File description:
** my_hexa_base
*/

#include "lib.h"
#include <stdlib.h>

int print_hexa_base(unsigned int nb, int j)
{
    char *hex = malloc(sizeof(int));
    char hexdec[17] = "0123456789abcdef";
    int tmp = 0;
    int first = 0;

    do {
        tmp = nb % 16;
        hex[first] = hexdec[tmp];
        nb = nb / 16;
        tmp = 0;
        first++;
    } while (nb != 0);
    hex = my_revstr(hex);
    j = my_putstr(hex, j);
    return (j);
}

int my_hexa(va_list *list, int j)
{
    unsigned int nb = va_arg(*list, unsigned int);

    if (handle_errors_unsigned(nb) == 84)
        return (84);
    j = print_hexa_base(nb, j);
    return (j);
}
