/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** transform a  string into an array of string
*/

#include "my.h"

int jump_nonalpha(char str);

int my_len(char *str, int i);

int biglen(char *str, int size);

char *convert(char const *src, char *dest, int *i);

char **my_str_to_word_array(char *str, int nb_lines)
{
    char **tab = NULL;
    int i = 0;
    int k = 0;
    int size = 0;
    int m = my_strlen(str);

    tab = malloc((sizeof(char *)) * (nb_lines) + 2);
    while (k < m) {
        if (jump_nonalpha(str[k]) == 0) {
            size = my_len(str, k);
            tab[i] = malloc((sizeof(char)) * (size) + 1);
            tab[i] = convert(str, tab[i], &k);
            i++;
        }
        k++;
    }
    tab[i] = NULL;
    return (tab);
}

int jump_nonalpha(char str)
{
    if (str == '\0')
        return (2);
    if (str == '\n')
        return (1);
    if (str == 'X' || str == 'O' )
        return (0);
    if (str == 'P' || str == ' ')
        return (0);
    if (str == '#')
        return (0);
    else
        exit (84);
}

int my_len(char *str, int i)
{
    int j = 0;
    int k = i;

    while (jump_nonalpha(str[k]) == 0) {
        j++;
        k++;
    }
    return (j);
}

char *convert(char const *src, char *dest, int *i)
{
    int j = 0;

    while (jump_nonalpha(src[*i]) == 0) {
        dest[j] = src[*i];
        *i += 1;
        j += 1;
    }
    dest[j] = '\0';
    return (dest);
}