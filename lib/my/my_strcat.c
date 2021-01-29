/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** my_strcat
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

char *my_strcat(char *dest, char *arg)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(arg) + 1));

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; arg[j] != '\0'; j++, i++)
        str[i] = arg[j];
    str[i] = '\0';
    return (str);
}