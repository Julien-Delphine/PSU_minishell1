/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>
#include <stdio.h>

int my_putchar(char c, int j)
{
    write(1, &c, 1);
    j++;
    return (j);
}
