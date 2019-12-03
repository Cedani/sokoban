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

OBJ		=		$(SRC:.c=.o)

NAME	=		my_sokoban

all:		$(OBJ)
		gcc $(OBJ) -o $(NAME) -lncurses

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.o
		rm -f $(NAME)

re: 	fclean all
