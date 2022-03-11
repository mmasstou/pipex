NAME = pipex
LIBFT = libft/libft.a


SRCS = srcs/pipex.c srcs/get.c srcs/pipex_utils.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcs/pipex_bonus.c
all: $(NAME)

$(NAME) : $(OBJS)
	@gcc -Wall -Wextra -Werror ${LIBFT}  $(SRCS) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex \033[0m\033[38;5;42m [Done] \033[0m";

bonus :

clean: 
	rm -f $(OBJS)
fclean : clean 

re : fclean all

.PHONY : all $(NAME) clean fclean re