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
//#include <stdio.h>

typedef struct s_player {
    int x;
    int y;
    int nb_line;
} t_player;

int my_strlen(char const *str);
int count_good_size(char *str);
char **my_str_to_word_array(char *str, int nb_lines);
char **loading_map(char const *filepath, int *nb_lines);
void moving(int ch, t_player *pl, char **map);
void check_player(char **map);
int finding_player(char **map, t_player *player);
int checking_win(char **map);
int jump_goodchar(char c);
void check_char(char **map);
char **error(char const *filepath, int *nb_lines, int **tab);
void opening_file(char const *filepath);
void check_bootle(char **map);
void reset_map(char const *filepath, char ***map, t_player *player);
void check_loosing(char **map);
int run_through(int y, int x, char **map);
void key_right_pressed(t_player *pl, char **map);
void key_left_pressed(t_player *pl, char **map);
void key_up_pressed(t_player *pl, char **map);
void key_down_pressed(t_player *pl, char **map);
int increase(int *x, char *comp, char *comp1);
int decrease(int *x, char *comp, char *comp1);
void event(char ***map, int c, t_player *pl, char const *filepath);
void game_loop(char **map, t_player *pl, int c, int *tab);
void init_var(char **map, t_player *pl);
int *manage_blank(char **map);
void display_blank(char **map, int *nb_o);
#endif /* !MY */
