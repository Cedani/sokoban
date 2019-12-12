/*
** EPITECH PROJECT, 2019
** reset.c
** File description:
** resetting map
*/

#include "my.h"

void reset_map(char const *filepath, char ***map, t_player *player)
{
    int nb_line;
    *map = error(filepath, &nb_line);
    finding_player(*map, player);
}

int check_lose(char comp)
{
    if (comp == '#')
        return (1);
    return (0);
}

int check_x(char **map)
{
    int x = 0;

    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            if (map[i][j] == 'X')
                x += 1;
    return (x);
}

void check_loosing(char **map)
{
    int check = 0;
    int tmp = 0;
    int k = check_x(map);
    for (int i = 0; map[i]; i += 1) {
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == 'X') {
                tmp = run_through(i, j, map);
            }
        }
        if (tmp > 3)
            check += 1;
        if (check <= check_x(map) && check >= checking_win(map)) {
            endwin();
            exit (1);
        }
        tmp = 0;
    }
}

int run_through(int y, int x, char **map)
{
    int tmp = 0;
    for (int i = y - 1; i <= y + 1; i += 1) {
        for (int j = x - 1; j <= x + 1; j += 1) {
            tmp += check_lose(map[i][j]);
        }
    }
    return (tmp);
}