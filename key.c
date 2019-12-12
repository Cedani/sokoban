/*
** EPITECH PROJECT, 2019
** manging key movement
** File description:
** key.c
*/

#include "my.h"

void key_up_pressed(t_player *pl, char **map)
{
    if (pl->y - 2 > 0)
            decrease(&pl->y, &map[pl->y - 1][pl->x], &map[pl->y - 2][pl->x]);
        else
            decrease(&pl->y, &map[pl->y - 1][pl->x], "#");
}

void key_down_pressed(t_player *pl, char **map)
{
    if (pl->y + 2 <= pl->nb_line - 1)
            increase(&pl->y, &map[pl->y + 1][pl->x], &map[pl->y + 2][pl->x]);
        else
            increase(&pl->y, &map[pl->y + 1][pl->x], "#");
}

void key_left_pressed(t_player *pl, char **map)
{
    if (pl->x - 2 > 0)
            decrease(&pl->x, &map[pl->y][pl->x - 1], &map[pl->y][pl->x - 2]);
        else
            decrease(&pl->x, &map[pl->y][pl->x - 1], "#");
}

void key_right_pressed(t_player *pl, char **map)
{
    if (pl->x + 2 <= my_strlen(map[pl->y]) - 1)
            increase(&pl->x, &map[pl->y][pl->x + 1], &map[pl->y][pl->x + 2]);
        else
            increase(&pl->x, &map[pl->y][pl->x + 1], "#");
}

void game_loop(char **map, t_player *pl, int c, int *tab)
{
    moving(c, pl, map);
    display_blank(map, tab);
    for (int i = 0; map[i]; i += 1)
            mvprintw(i, 0, "%s", map[i]);
    mvprintw(pl->y, pl->x, "%c", 'P');
}