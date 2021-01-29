/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

void reverse(char *str, int count, int reverse_count)
{
    while (str[count] != '\0')
        count++;

    char temp_str[count];
    reverse_count = count - 1;
    count = 0;

    while (str[count] != '\0') {
        temp_str[count] = str[count];
        count++;
    } temp_str[count] = str[count];
    count = 0;
    while (reverse_count >= 0) {
        str[count] = temp_str[reverse_count];
        reverse_count--;
        count++;
    }
}

char *my_revstr(char *str)
{
    int count = 0;
    int reverse_count = 0;

    reverse(str, count, reverse_count);
    return (str);
}
