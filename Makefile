##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		my_popup.c 	\
				my_strlen.c 	\
				loading_map.c 	\
				my_str_to_word_array.c 	\
				movement.c 				\
				checkers.c 				\
				reset.c 				\
				key.c 					\
				manage_blank.c 			\
				my_putchar.c 			\
				my_putstr.c 			\
				my_strcmp.c 			\



OBJ		=		$(SRC:.c=.o)

NAME	=		my_sokoban

all:		$(OBJ)
		gcc $(OBJ) -o $(NAME) -lncurses -g3

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.o
		rm -f $(NAME)

re: 	fclean all
