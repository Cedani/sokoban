/*
** EPITECH PROJECT, 2019
** manage_blank.c
** File description:
** manage blank
*/

#include "my.h"

int *manage_blank(char **map)
{
    int blank = 0;
    int *tab;
    int k = 0;

    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            if (map[i][j] == 'O')
                blank += 1;
    tab = malloc(sizeof(*tab) * (blank * 2));
    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == 'O') {
                tab[k] = i;
                tab[k + 1] = j;
                k += 2;
            }
        }
    return (tab);
}

void display_blank(char **map, int *nb_o)
{
    for (int i = 0; nb_o[i]; i += 2) {
        if (map[nb_o[i]][nb_o[i + 1]] == ' ')
            map[nb_o[i]][nb_o[i + 1]] = 'O';
    }
}