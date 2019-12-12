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
    char **map = error(argv[1], &nb_lines);
    t_player player;
    player.nb_line = nb_lines;

    init_var(map, &player);
    initscr();
    curs_set(0);
    while (c != 'x') {
        clear();
        game_loop(map, &player, c);
        c = getch();
        refresh();
        event(map, c, &player, argv[1]);
    }
    free(map);
    endwin();
    return (0);
}