/*
** EPITECH PROJECT, 2019
** my_charvalist
** File description:
** my_charvalist
*/

#include <stdarg.h>
#include <unistd.h>

int my_char(va_list *list, int j)
{
    char c = va_arg(*list, int);

    write(1, &c, 1);
    j++;
    return (j);
}
