/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** compare 2 string
*/

#include <stdio.h>

int my_strcmp(char *buffer, char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] != buffer[i])
            return (84);
        i++;
    }
    return (0);
}

int my_strstr(char *str, char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (str[i] != buffer[i])
            return (84);
        i++;
    }
    return (0);
}