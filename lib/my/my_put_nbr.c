/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display int
*/

#include "lib.h"
#include <stdarg.h>

int print_nbr(int nbr, int j)
{
    if (nbr < 0) {
        j = my_putchar('-', j);
        j = my_putchar((nbr / 10) * -1, j);
        j = my_putchar(((nbr % 10) * -1) + '0', j);
    }
    else {
        if (nbr >= 10)
            j = print_nbr(nbr /10, j);
        j = my_putchar((nbr % 10) + '0', j);
    }
    return (j);
}

int my_nbr(va_list *list, int j)
{
    int nbr = va_arg(*list, int);

    if (handle_errors_int(nbr) == 84)
        return (84);
    j = print_nbr(nbr, j);
    return (j);
}
