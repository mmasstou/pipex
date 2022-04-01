NAME = pipex
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS_GET_NEXT_LINE = $(GET_NEXT_LINE:.c=.o)

SRCS = srcs/cmds_process.c srcs/pipex_bonus_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c  srcs/get_path_cmd.c
OBJS = $(SRCS:.c=.o)

SRCS_MANDATORY = srcs/pipex.c
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

SRCS_BONUS = srcs/pipex_bonus.c srcs/here_doc.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o:%.c
	@${CC} ${CFLAGS} -I . -o $@ -c $<
	@printf "\x1b[36m   +>\033[0m compiling \033[38;5;42m$< \033[0m\n"
	

all: _LIBFT $(NAME) 


$(NAME) :  $(OBJS) $(OBJS_MANDATORY) $(OBJS_GET_NEXT_LINE)
	@$(CC) $(CFLAGS) ${LIBFT}  $(OBJS_MANDATORY) $(OBJS) $(OBJS_GET_NEXT_LINE) -o $(NAME) -g
	@echo "\x1b[36m   +> pipex Mandatory \033[0m\033[38;5;42m [Done] \033[0m";

bonus : _LIBFT $(OBJS) $(OBJS_BONUS) $(OBJS_GET_NEXT_LINE)
	@$(CC) $(CFLAGS) ${LIBFT} $(OBJS) $(OBJS_BONUS) $(OBJS_GET_NEXT_LINE) -o $(NAME) -g
	@echo "\x1b[36m   +> pipex Bonus \033[0m\033[38;5;42m [Done] \033[0m";
	
_LIBFT : 
	@make -C libft
	@cp ./libft/libft.a .

push:fclean
	@rm -rf outfile
	@git add .
	@read -p "Message:" message; \
	git commit -m "$$message"; \
	git push origin master
	
valgrind_m:fclean  all
	@rm -rf outfile
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./pipex srcs/pipex_bonus.c "grep index"  "wc -l"  outfile

error_m:fclean all
	@rm -rf outfile
	@valgrind --leak-check=full --show-leak-kinds=all ./pipex srcs/pipex_bonus.c  "grep index"  "grep int"  outfile

valgrind_b:fclean  bonus
	@rm -rf outfile
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./pipex srcs/pipex_bonus.c cat "grep index"  "grep int" "wc -l"  outfile

error:fclean bonus
	@rm -rf outfile
	@valgrind --leak-check=full --show-leak-kinds=all ./pipex srcs/pipex_bonus.c cat "grp index"  "grep int" "wc -l"  outfile

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
fclean : clean 
	@make fclean -C ./libft
	@rm -f $(NAME) $(LIBFT) 
	@echo "\x1b[36m   +> Clean $(NAME) \033[0m\033[38;5;42m [Done] \033[0m";

re : fclean all
	@make re -C ./libft/

.PHONY : all $(NAME) clean fclean re