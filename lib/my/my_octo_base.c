/*
** EPITECH PROJECT, 2019
** my_octo_base
** File description:
** my_octo_base
*/

#include "lib.h"
#include <stdarg.h>

int print_octo_base(unsigned int nb, int j)
{
    if (nb >= 8)
        j = print_octo_base(nb /8, j);
    j = my_putchar((nb % 8) + '0', j);
    return (j);
}

int my_octo(va_list *list, int j)
{
    unsigned int nb = va_arg(*list, unsigned int);

    if (handle_errors_unsigned(nb) == 84)
        return (84);
    j = print_octo_base(nb, j);
    return (j);
}
