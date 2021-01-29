/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** Handling error
*/

#include "mysh.h"

int check_only_space_tab(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\n') {
        if (str[i] != ' ' && str[i] != '\t')
            j++;
        i++;
    }
    if (j == 0)
        return (84);
    return (0);
}

int handle_errors(char *buffer)
{
    if (check_only_space_tab(buffer) == 84) {
        my_printf("$> ");
        return (84);
    }
    if (buffer[0] == '\n') {
        my_printf("$> ");
        return (84);
    }
    return (0);
}