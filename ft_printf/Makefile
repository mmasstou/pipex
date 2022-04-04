NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRC = 

OBJS = ${SRC:.c=.o}

%.c:%.o
	$(CC) $(CFLAGS) -I . -o $@ -c $<
	@printf "\x1b[36m   +>\033[0m compiling \033[38;5;42m$< \033[0m\n"

all : $(NAME)


$(NAME): $(OBJS)
	@ar ac $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[36m   +> Clean $(NAME) \033[0m\033[38;5;42m [Done] \033[0m";

re: fclean all

.PHONY : all bonus clean fclean re