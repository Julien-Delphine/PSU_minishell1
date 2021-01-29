/*
** EPITECH PROJECT, 2019
** binary base
** File description:
** binary
*/

#include "lib.h"
#include <stdarg.h>

int print_binary_base(unsigned int nb, int j)
{
    if (nb >= 2)
        j = print_binary_base(nb /2, j);
    j = my_putchar((nb % 2) + '0', j);
    return (j);
}

int my_binary(va_list *list, int j)
{
    unsigned int nb = va_arg(*list, unsigned int);

    if (handle_errors_unsigned(nb) == 84)
        return (84);
    j = print_binary_base(nb, j);
    return (j);
}
