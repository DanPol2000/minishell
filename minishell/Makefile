NAME = minishell

CC = gcc -lreadline

CFLAGS = -Wall -Werror -Wextra -MMD -g

INC = minishell.h

SRC	   = main.c utils.c lexer.c env.c handler.c

OBJ = $(patsubst %.c,%.o,$(SRC))

D_OBJ = $(patsubst %.c,%.d,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[0;33m\n\nCompiling minishell..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n\033[0;36mDone."

%.o : %.c $(INC)
	@printf "\033[0;34mGenerating minishell objects... %-10.10s\r" $@
	gcc $(CFLAGS) -c $< -o $@

clean :
	@echo "\033[0;31m\nDeleting objects..."
	rm -f $(OBJ) $(D_OBJ)
	@echo "\n\033[0;31mDeleted.\n"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
