NAME = pipex
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS_GET_NEXT_LINE = $(GET_NEXT_LINE:.c=.o)

SRCS =  srcs/pipex_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c srcs/create_env.c srcs/get_path_cmd.c
OBJS = $(SRCS:.c=.o)

SRCS_MANDATORY = srcs/pipex.c
OBJS_MANDATORY = $(SRCS_BONUS:.c=.o)

SRCS_BONUS = srcs/pipex_bonus.c srcs/here_doc.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o:%.c pipex.h  pipex_bonus.h Makefile
	@${CC} ${CFLAGS} -I . -o $@ -c $<

all: $(NAME)


$(LIBFT) :
	@make -C libft
	@cp ./libft/libft.a .

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) ${LIBFT}  $(SRCS_MANDATORY) $(SRCS) $(GET_NEXT_LINE) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex Mandatory \033[0m\033[38;5;42m [Done] \033[0m";

bonus : $(LIBFT)
	@$(CC) $(CFLAGS) ${LIBFT} $(SRCS_BONUS) $(SRCS) $(GET_NEXT_LINE) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex Bonus \033[0m\033[38;5;42m [Done] \033[0m";
	@rm -rf outfile
clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
fclean : clean 
	@make fclean -C ./libft
	@rm -f $(NAME) $(LIBFT) 

re : fclean all
	@make re -C ./libft/

.PHONY : all $(NAME) clean fclean re