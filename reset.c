/*
** EPITECH PROJECT, 2019
** reset.c
** File description:
** resetting map
*/

#include "my.h"

void reset_map(char const *filepath, char ***map, t_player *player)
{
    int nb_line;
    *map = error(filepath, &nb_line);
    finding_player(*map, player);
}