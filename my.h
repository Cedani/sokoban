/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** useful functions
*/

#ifndef MY
#define MY
#include <unistd.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_player {
    int x;
    int y;
    int nb_line;
} t_player;

typedef struct s_limit {
    int x_lim;
    int y_lim;
} t_limit;

int my_strlen(char const *str);
int count_good_size(char *str);
char **my_str_to_word_array(char *str, int nb_lines);
char **loading_map(char const *filepath, int *nb_lines);
void moving(int ch, t_player *pl, char **map);
void check_player(char **map);
int finding_player(char **map, t_player *player);
int checking_win(char **map);
#endif /* !MY */
