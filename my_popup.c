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
    char **map = loading_map(argv[1], &nb_lines);
    t_player player;
    player.nb_line = nb_lines;

    check_player(map);
    finding_player(map, &player);
    initscr();
    curs_set(0);
    while (c != 32) {
        for (int i = 0; map[i]; i += 1) {
            mvprintw(i, 0, "%s", map[i]);
        }
        mvprintw(player.y, player.x, "%c", 'P');
        c = getch();
        moving(c, &player, map);
        clear();
        refresh();
        if (checking_win(map) == 0)
            exit (0);
    }
    endwin();
    return (0);
}