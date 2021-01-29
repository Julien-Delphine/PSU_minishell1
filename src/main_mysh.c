/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main for minishell
*/

#include "mysh.h"

void ctrl_c(int i)
{
    if (i == 2)
        my_printf("\n$> ");
}

char *clean_buffer(t_getarg *getarg)
{
    int i = 0;
    int j = 0;
    char *new = NULL;

    if (getarg->buffer[0] == ' ' || getarg->buffer[0] == '\t') {
        for (; getarg->buffer[i] == ' ' || getarg->buffer[i] == '\t'; i++)
        new = malloc(sizeof(char) * (my_strlen(getarg->buffer) - i + 1));
        for (; getarg->buffer[i] != '\0'; i++, j++)
            new[j] = getarg->buffer[i];
        new[j] = '\0';
    }
    else {
        new = malloc(sizeof(char) * (my_strlen(getarg->buffer) + 1));
        for (; getarg->buffer[i] != '\0'; i++)
            new[i] = getarg->buffer[i];
        new[i] = '\0';
    }
    return (new);
}

char **my_get_env(char **env)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = NULL;
    char *str;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H') {
            str = malloc(sizeof(char) * my_strlen((env[i]) + 1));
            for (; env[i][j] != '/'; j++);
            for (; env[i][j] != '\0'; j++, k++)
                str[k] = env[i][j];
            str[k] = '\0';
            array = my_str_to_word_array(str, ':');
        }
        i++;
    }
    if (array == NULL)
        exit(84);
    return (array);
}

void main_minishell(char **env, t_getarg getarg, char **get_env)
{
    char **arg;
    getarg.buffer = NULL;
    char *str = NULL;
    size_t buffsize = 0;

    signal(SIGINT, ctrl_c);
    while (1) {
        if (getline(&getarg.buffer, &buffsize, stdin) == -1)
            exit(ERROR_GETLINE);
        if (handle_errors(getarg.buffer) == 84)
            main_minishell(env, getarg, get_env);
        str = clean_buffer(&getarg);
        arg = my_str_to_word_array(str, 32);
        my_exit(str, arg);
        if (my_cd(str, arg, env) == 1)
            return (main_minishell(env, getarg, get_env));
        my_pid(env, get_env, arg);
        my_printf("$> ");
    }
}

int main(int ac, char **av, char **env)
{
    t_getarg getarg;
    char **get_env;

    my_printf("$> ");
    get_env = my_get_env(env);
    main_minishell(env, getarg, get_env);
    return (0);
}