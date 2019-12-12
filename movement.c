/*
** EPITECH PROJECT, 2019
** getters
** File description:
** gets the position of the Player and define possible movement
*/

#include "my.h"

int finding_player(char **map, t_player *player)
{
    for (int j = 0; map[j]; j += 1) {
        for (int i = 0; map[j][i]; i += 1) {
            if (map[j][i] == 'P') {
                player->x = i;
                player->y = j;
                map[j][i] = ' ';
                return (0);
            }
        }
    }
}

int increase(int *x, char *comp, char *comp1)
{
    if (comp[0] == 'X') {
        if (comp1[0] != '#' && comp1[0] != 'X') {
            comp1[0] = comp[0];
            comp[0] = ' ';
            *x += 1;
            return (0);
        }
    }
    if (comp[0] == 'X')
        return (0);
    if (comp[0] != '#')
        *x += 1;
}

int decrease(int *x, char *comp, char *comp1)
{
    if (comp[0] == 'X' && comp1[0] != 'X') {
        if (comp1[0] != '#') {
            comp1[0] = comp[0];
            comp[0] = ' ';
            *x -= 1;
            return (0);
        }
    }
    if (comp[0] == 'X')
        return (0);
    if (comp[0] != '#')
        *x -= 1;
}

void moving(int ch, t_player *pl, char **map)
{
    keypad(stdscr, TRUE);
    if (ch == KEY_UP) {
        key_up_pressed(pl, map);
    }
    if (ch == KEY_DOWN) {
        key_down_pressed(pl, map);
    }
    if (ch == KEY_LEFT) {
        key_left_pressed(pl, map);
    }
    if (ch == KEY_RIGHT) {
        key_right_pressed(pl, map);
    }
}

int checking_win(char **map)
{
    int check = 0;

    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            if (map[i][j] == 'O')
                check += 1;
    return (check);
}