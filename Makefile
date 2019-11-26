##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		my_popup.c 	\
				my_strlen.c 	\

OBJ		=		$(SRC:.c=.o)

NAME	=		my_popup

all:		$(OBJ)
		gcc $(OBJ) -o $(NAME) -lncurses

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.o
		rm $(NAME)

re: 	fclean all
