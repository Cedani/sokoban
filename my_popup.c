/*
** EPITECH PROJECT, 2019
** my_popup.c
** File description:
** put a char on middle windows
*/

#include "my.h"

int main(int argc, char **argv)
{
    int nb_lines;
    int c = 0;
    int *tab;
    char **map = error(argv[1], &nb_lines, &tab);
    t_player player;
    player.nb_line = nb_lines;

    init_var(map, &player);
    initscr();
    curs_set(0);
    while (c != 'x') {
        clear();
        game_loop(map, &player, c, tab);
        c = getch();
        event(&map, c, &player, argv[1]);
        refresh();
    }
    endwin();
    free(map);
    return (0);
}