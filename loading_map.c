/*
** EPITECH PROJECT, 2019
** loading_map.c
** File description:
** load game map
*/

#include "my.h"

char **error(char const *filepath, int *nb_lines)
{
    char **map;

    opening_file(filepath);
    map = loading_map(filepath, nb_lines);
    check_char(map);
    check_bootle(map);
    check_player(map);
    return (map);
}

char **loading_map(char const *filepath, int *nb_lines)
{
    struct stat stat1;
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    char **map;

    stat(filepath, &stat1);
    buffer = malloc(sizeof(*buffer) * stat1.st_size + 1);
    read(fd, buffer, stat1.st_size);
    buffer[stat1.st_size] = '\0';
    *nb_lines = count_good_size(buffer);
    map = my_str_to_word_array(buffer, *nb_lines);
    close(fd);
    free(buffer);
    return (map);
}

int count_good_size(char *str)
{
    int j = 0;
    for (int i = 0; str[i]; i += 1)
        if (str[i] == '\n')
            j += 1;
    return (j);
}

void init_var(char **map, t_player *pl)
{
    check_player(map);
    finding_player(map, pl);
}

void event(char **map, int c, t_player *pl, char const *filepath)
{
    refresh();
    if (c == 32)
        reset_map(filepath, &map, pl);
    if (checking_win(map) == 0) {
        endwin();
        exit (0);
    }
    check_loosing(map);
}