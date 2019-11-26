/*
** EPITECH PROJECT, 2019
** my_popup.c
** File description:
** put a char on middle windows
*/

#include "my.h"

int main(int argc, char **argv)
{
    int y = 0;
    int x = 0;
    int ch;

    initscr();
    getmaxyx(stdscr, y, x);

    y /= 2;
    x /= 2;
    while (ch != 32) {
        mvprintw(y, x, "%s", argv[1]);
        ch = getch();
        if (ch == 'z')
            y--;
        if (ch == 'q')
            x--;
        if (ch == 's')
            y++;
        if (ch == 'd')
            x++;
        clear();
        refresh();
    }
    endwin();

    return (0);
}