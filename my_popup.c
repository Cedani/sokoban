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
    int nb_lines2;
    int c = 0;
    char **map = error(argv[1], &nb_lines);
    char **test = error(argv[1], &nb_lines);
    t_player player;
    player.nb_line = nb_lines;

    check_player(map);
    finding_player(map, &player);
    initscr();
    curs_set(0);
    while (checking_win(map) != 0 && c != 'x') {
        clear();
        moving(c, &player, map);
        for (int i = 0; map[i]; i += 1)
            mvprintw(i, 0, "%s", map[i]);
        mvprintw(player.y, player.x, "%c", 'P');
        c = getch();
        refresh();
        if (c == 32)
            reset_map(argv[1], &map, &player);
    }
    free(map);
    endwin();
    return (0);
}