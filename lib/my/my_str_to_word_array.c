/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** str to word array with charac for separation of arg
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void clean_str(value_array_t *value, char *buffer, char charac)
{
    if (buffer[value->i] == charac || buffer[value->i] == '\n'
    || buffer[value->i] == '\t') {
        while (buffer[value->i] == charac || buffer[value->i] == '\t')
            value->i++;
        value->j++;
        value->k = 0;
    }
}

void init_value(value_array_t *value)
{
    value->i = 0;
    value->j = 0;
    value->k = 0;
}

int my_strl(char *str, char charac)
{
    int i = 0;

    while ((str[i] != '\0') && (str[i] != '\n') && (str[i] != charac)) {
        i++;
    }
    return (i);
}

int countword(char *buffer, char charac)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if ((buffer[i] == charac && buffer[i + 1] != '\0')
        || (buffer[i] == '\t' && buffer[i + 1] != '\0'))
            j++;
        i++;
    }
    return (j);
}

char **my_str_to_word_array(char *buffer, char charac)
{
    char **array = malloc(sizeof(char *) * ((countword(buffer, charac) + 2)));
    value_array_t *val = malloc(sizeof(value_array_t));

    init_value(val);
    if (array == NULL)
        exit(84);
    while (buffer[val->i] != '\n' && buffer[val->i] != '\0') {
        clean_str(val, buffer, charac);
        array[val->j] = malloc(sizeof(char) * ((my_strl(buffer, charac) + 3)));
        if (array[val->j] == NULL)
            exit(84);
        while ((buffer[val->i] != '\0') && (buffer[val->i] != '\n')
        && (buffer[val->i] != charac) && buffer[val->i] != '\t') {
            array[val->j][val->k] = buffer[val->i];
            val->k++;
            val->i++;
        }
        array[val->j][val->k] = '\0';
    }
    array[val->j + 1] = NULL;
    return (array);
}