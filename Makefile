##
## EPITECH PROJECT, 2018
## mysh
## File description:
## Makefile
##

SRC_DIR	=	$(realpath ./src)

SRC	=	$(SRC_DIR)/mysh.c				\
		$(SRC_DIR)/pipe/separat.c			\
		$(SRC_DIR)/pipe/exec_part.c			\
		$(SRC_DIR)/pipe/exec2.c				\
		$(SRC_DIR)/pipe/exec3.c				\
		$(SRC_DIR)/pipe/parsing.c			\
		$(SRC_DIR)/pipe/parsing2.c			\
		$(SRC_DIR)/pipe/exec_pipe.c			\
		$(SRC_DIR)/pipe/exec.c				\
		$(SRC_DIR)/str_word_to_array.c			\
		$(SRC_DIR)/exec.c				\
		$(SRC_DIR)/prompt.c				\
		$(SRC_DIR)/builtins.c				\
		$(SRC_DIR)/setenv.c				\
		$(SRC_DIR)/my_show.c				\
		$(SRC_DIR)/unsetenv.c				\
		$(SRC_DIR)/my_cd.c				\
		$(SRC_DIR)/exec2.c				\
		$(SRC_DIR)/alias.c				\
		$(SRC_DIR)/fct_recup.c				\
		$(SRC_DIR)/create_alias.c			\
		$(SRC_DIR)/history.c				\
		$(SRC_DIR)/pcommands.c				\
		$(SRC_DIR)/path.c				\
		$(SRC_DIR)/put_in_file.c			\
		$(SRC_DIR)/pipe.c				\
		$(SRC_DIR)/info_prompt.c			\
		$(SRC_DIR)/info_prompt2.c			\
		$(SRC_DIR)/pcommands2.c				\
		$(SRC_DIR)/exec3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	+=	-W -Wextra -Wall
CFLAGS	+=	-Iinclude

LDFLAGS	+=	-Llib -lmy

all: lib $(NAME)

lib:
	cd lib ; make

$(NAME): $(OBJ)
	gcc -o $(NAME)	$(OBJ) $(LDFLAGS)

clean:
	find -iname '*.o' -delete

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a

re: fclean all

.PHONY: all clean fclean re lib
