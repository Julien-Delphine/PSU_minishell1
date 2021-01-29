/*
** EPITECH PROJECT, 2019
** my_unsigned_nbr
** File description:
** my_unsigned_nbr
*/

#include "lib.h"
#include <stdarg.h>

int print_u_nbr(unsigned int nbr, int j)
{
    if (nbr >= 10)
        j = print_nbr(nbr /10, j);
    j = my_putchar((nbr % 10) + '0', j);
    return (j);
}

int my_u_nbr(va_list *list, int j)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    if (handle_errors_unsigned(nbr) == 84)
        return (84);
    j = print_u_nbr(nbr, j);
    return (j);
}
