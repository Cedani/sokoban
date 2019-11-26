/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_strlen.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
