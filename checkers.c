/*
** EPITECH PROJECT, 2019
** checker.c
** File description:
** check authorized character
*/

#include "my.h"

int jump_goodchar(char c)
{
    if (c == ' ')
        return (0);
    if (c == '\n')
        return (0);
    if (c == 'P')
        return (0);
    if (c == 'X')
        return (0);
    if (c == '#')
        return (0);
    if (c == 'O')
        return (0);
    return (1);
}

void check_char(char **map)
{
    for (int i = 0; map[i]; i += 1) {
        for (int j = 0; map[i][j]; j += 1)
            if (jump_goodchar(map[i][j]) == 1) {
                write(2, "unauthorized character\n", 23);
                exit(84);
            }
    }
}

void check_bootle(char **map)
{
    int nb_o = 0;
    int nb_x = 0;

    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == 'O')
                nb_o += 1;
            if (map[i][j] == 'X')
                nb_x += 1;
        }
    if (nb_o != nb_x) {
        write (2, "wrong number of bottle or blanks\n", 35);
        exit (84);
    }
    if (nb_o == 0 || nb_x == 0) {
        write (2, "wrong number of bottle or blanks\n", 33);
        exit (84);
    }
}

void check_player(char **map)
{
    int nb = 0;

    for (int i = 0; map[i]; i += 1)
        for (int j = 0; map[i][j]; j += 1) {
            if (map[i][j] == 'P')
                nb += 1;
        }
    if (nb != 1) {
        write(2, "bad number of player\n", 21);
        exit (84);
    }
}

void opening_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "wrong file\n", 11);
        exit (84);
    }
    close (fd);
}