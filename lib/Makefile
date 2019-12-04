##
## EPITECH PROJECT, 2017
## lib
## File description:
## Makefile
##

SRC_DIR	=	$(realpath ./src_lib)

SRC	=	$(SRC_DIR)/my_printf.c			\
		$(SRC_DIR)/my_print1.c			\
		$(SRC_DIR)/my_put_nbr.c			\
		$(SRC_DIR)/my_putchar.c			\
		$(SRC_DIR)/my_put_hexa.c 		\
		$(SRC_DIR)/my_put_nbr_ui.c		\
		$(SRC_DIR)/my_print2.c			\
		$(SRC_DIR)/my_getnbr.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I../include

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re