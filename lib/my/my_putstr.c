/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display string
*/

#include "lib.h"

int my_putstr(char *str, int j)
{
    int i = 0;
    handle_errors_str(str);

    while (str[i] != '\0') {
        j = my_putchar(str[i], j);
        i++;
    }
    return (j);
}
