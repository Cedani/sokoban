/*
** EPITECH PROJECT, 2019
** loading_map.c
** File description:
** load game map
*/

#include "my.h"

int error(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char s;

    if (fd == -1) {
        exit (84);
    }
    close (fd);
    return (0);
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