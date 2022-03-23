NAME = pipex
LIBFT = libft/libft.a

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS_GET_NEXT_LINE = $(GET_NEXT_LINE:.c=.o)

SRCS = srcs/pipex.c  srcs/pipex_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c srcs/create_env.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcs/pipex_bonus.c srcs/here_doc.c     srcs/pipex_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c srcs/create_env.c srcs/get_path_cmd.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@gcc -Wall -Wextra -Werror ${LIBFT}  $(SRCS) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex \033[0m\033[38;5;42m [Done] \033[0m";

bonus :
	@gcc -Wall -Wextra -Werror ${LIBFT} $(SRCS_BONUS) $(GET_NEXT_LINE) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex Bonus \033[0m\033[38;5;42m [Done] \033[0m";
	rm -rf outfile
clean: 
	rm -f $(OBJS) $(OBJS_BONUS)
fclean : clean 

re : fclean all

.PHONY : all $(NAME) clean fclean re