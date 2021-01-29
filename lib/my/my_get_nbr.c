/*
** EPITECH PROJECT, 2020
** get number
** File description:
** get number in a string
*/

int my_getnbr(char const *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if ((str[i] < '0' || str[i] > '9'))
            return (0);
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}
