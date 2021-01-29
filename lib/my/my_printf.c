/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "include/lib.h"
#include <unistd.h>

int find_flag(char element)
{
    char index[11] = {'s', 'S', 'c', 'd', 'i', 'u', 'o', 'x', 'X', 'b', 0};

    for (int i = 0; index[i] != 0; i++) {
        if (index[i] == element)
            return (i);
    }
    return (84);
}

int my_printf(char *str, ...)
{
    int (*functions[10])() = {my_str, my_str,my_char, my_nbr,
                            my_nbr, my_u_nbr, my_octo,
                            my_hexa, my_maj_hexa, my_binary};
    va_list list;
    int Index = 0;
    int i = 0;
    int j = 0;

    va_start(list, str);
    for (i = 0; str[i] != '\0'; i++){
        if (i != 0 && str[i - 1] == '%') {
            Index = find_flag(str[i]);
            if (Index == 84)
                return (84);
            j = (functions[Index])(&list, j);
        }
        else if (str[i] != '%')
            j = my_putchar(str[i], j);
    }
    va_end(list);
    return (j);
}

