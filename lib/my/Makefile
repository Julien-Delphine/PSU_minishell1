##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_octo_base.c	\
		my_putchar.c	\
		my_hexa_base.c	\
		my_revstr.c	\
		my_strvalist.c	\
		my_charvalist.c	\
		my_maj_hexa.c	\
		my_binary_base.c	\
		my_u_nbr.c	\
		handle_errors.c		\
		my_strstr.c			\
		my_str_to_word_array.c	\
		my_get_nbr.c	\
		my_strlen.c		\
		my_strcat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

LIB	=	-L. -lmy

CFLAGS	=	-I./include -Wextra -Wall -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(TOBJ)

fclean:	clean
	rm -f libmy.a
	rm -f *.o

re:	fclean all
