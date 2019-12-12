/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap  file representing the warehouse map,  containing ‘#’");
    my_putstr(" for walls, \n\t‘P’ for the player, ‘X’ for boxes and ‘O’");
    my_putstr("for storage locations.\n");
}