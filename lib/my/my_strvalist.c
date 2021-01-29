/*
** EPITECH PROJECT, 2019
** my_putstr va_list
** File description:
** my_putstr with va_list
*/

#include "lib.h"
#include <stdio.h>

int my_str(va_list *list, int j)
{
    char *str = va_arg(*list, char *);
    int i = 0;

    if (handle_errors_str(str) == 84) {
        my_putstr("(null)", j);
        return (0);
    }
    while (str[i] != '\0') {
        j = my_putchar(str[i], j);
        i++;
    }
    return (j);
}
