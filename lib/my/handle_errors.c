/*
** EPITECH PROJECT, 2019
** handle errors
** File description:
** handle errors
*/

#include <stdlib.h>
#include "lib.h"

int handle_errors_str(char *str)
{

    if (str == NULL)
        return (EXIT_ERROR);
    return (0);
}

int handle_errors_int(int i)
{
    char str[2] = {i, '\0'};

    if (str == NULL)
        return (EXIT_ERROR);
    return (0);
}

int handle_errors_unsigned(unsigned int i)
{
    char str[2] = {i, '\0'};

    if (str == NULL)
        return (EXIT_ERROR);
    return (0);
}
