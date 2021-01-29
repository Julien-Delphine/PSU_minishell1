/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** function for minishell
*/

#include "mysh.h"

char **get_old_pwd(char **env)
{
    char **get_pwd;
    char *str;
    int i = 0;
    int j = 0;
    int k = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D') {
            str = malloc(sizeof(char) * my_strlen((env[i]) + 1));
            for (; env[i][j] != '/'; j++);
            for (; env[i][j] != '\0'; j++, k++)
                str[k] = env[i][j];
            get_pwd = my_str_to_word_array(str, ':');
        }
        i++;
    }
    return (get_pwd);
}

int my_exec(char *get_env, char *str, char **arg, char **env)
{
    pid_t pid;
    DIR *dir = opendir(get_env);
    struct dirent *read_f = NULL;
    int status = 0;
    int i = 0;

    if (dir == NULL)
        return (100);
    while ((read_f = readdir(dir)) != NULL) {
        if (my_strstr(read_f->d_name, arg[0]) == 0) {
            i++;
            str = my_strcat(str, arg[0]);
            if ((pid = fork()) == 0) {
                execve(str, arg, env);
                exit(0);
            }
            wait(&status);
        }
    }
    return (i);
}

int my_pid(char **env, char **get_env, char **arg)
{
    int j = 0;

    for (int i = 0; get_env[i]; i++) {
        char *str = my_strcat(get_env[i], "/");
        if (access(get_env[i], F_OK) == 0 && access(get_env[i], R_OK) == 0
        && access(get_env[i], X_OK) == 0)
            j = my_exec(get_env[i], str, arg, env);
        if (j != 0)
            return (0);
    }
    my_printf("%s: Command not found.\n", arg[0]);
    return (0);
}

void my_exit(char *buffer, char **arg)
{
    int i = 0;

    if (my_strcmp("exit\n", buffer) == 0) {
        if (arg[1] != NULL)
            i = my_getnbr(arg[1]);
        exit(i);
    }
}

int my_cd(char *buffer, char **arg, char **env)
{
    char **get_pwd;

    if (my_strcmp("cd\n", buffer) == 0) {
        if (arg[1] == NULL) {
            return (0);
        }
        if (arg[1] != NULL && my_strcmp("-\n", arg[1]) == 0) {
            get_pwd = get_old_pwd(env);
            chdir(get_pwd[0]);
            return (0);
        }
    }
    if (my_strstr(buffer, "cd") == 0) {
        if (chdir(arg[1]) == -1)
            my_printf("%s: No such file or directory.\n", arg[1]);
        my_printf("$> ");
        return (1);
    }
    return (0);
}