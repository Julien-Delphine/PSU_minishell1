/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** include for minishell
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include "../lib/my/include/lib.h"
#include <signal.h>

#ifndef MINISHELL_
#define MINISHELL_
#define SUCCESS 0
#define ERROR_GETLINE 84

typedef struct minishell
{
    char **arg;
    char *buffer;
    pid_t pid;
    int fd;
} t_getarg;

void my_exit(char *buffer, char **arg);
int my_cd(char *buffer, char **arg, char **env);
int my_pid(char **env, char **get_env, char **arg);
int handle_errors(char *buffer);

#endif /* MINISHELL_ */