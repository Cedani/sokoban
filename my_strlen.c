/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void display_end(char **map, t_player *pl)
{
    clear();
    for (int i = 0; map[i]; i += 1)
        mvprintw(i, 0, "%s", map[i]);
    mvprintw(pl->y, pl->x, "%c", 'P');
    refresh();
    endwin();
    exit (1);
}
