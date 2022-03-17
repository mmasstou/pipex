NAME = pipex
LIBFT = libft/libft.a


SRCS = srcs/pipex.c srcs/get_commend.c srcs/pipex_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c srcs/create_env.c
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