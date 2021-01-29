##
## EPITECH PROJECT, 2020
## Minishell
## File description:
## Makefile for minishell
##

SRC	=	src/main_mysh.c		\
		src/handle_errors.c		\
		src/functions.c

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -g

IFLAGS	=	-I./include/

LIB		=	-L lib/my/ -l my

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(IFLAGS) $(SRC) $(LIB)

clean:
	make -C lib/my clean
	rm -f *.o
	rm -f *.~

fclean:
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *.~

re:	fclean all