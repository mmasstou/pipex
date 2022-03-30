NAME = pipex
LIBFT = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS_GET_NEXT_LINE = $(GET_NEXT_LINE:.c=.o)

SRCS = srcs/cmds_process.c srcs/pipex_bonus_utils.c srcs/open_file.c srcs/errors.c srcs/get_path.c srcs/child_process.c srcs/pipex_free.c  srcs/get_path_cmd.c
OBJS = $(SRCS:.c=.o)

SRCS_MANDATORY = srcs/pipex.c
OBJS_MANDATORY = $(SRCS_BONUS:.c=.o)

SRCS_BONUS = srcs/pipex_bonus.c srcs/here_doc.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o:%.c 
	@${CC} ${CFLAGS} -c $<
	@echo  Compiling $< :"\x1B[1;32m[ok]\x1B[0m"

all: $(NAME)


$(LIBFT) :
	@make -C libft
	@cp ./libft/libft.a .

$(NAME) : $(OBJS) $(LIBFT) $(OBJS_MANDATORY)
	@$(CC) $(CFLAGS) ${LIBFT}  $(SRCS_MANDATORY) $(SRCS) $(GET_NEXT_LINE) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex Mandatory \033[0m\033[38;5;42m [Done] \033[0m";

bonus : $(LIBFT) $(OBJS) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) ${LIBFT} $(SRCS_BONUS) $(SRCS) $(GET_NEXT_LINE) -o $(NAME) -g
	@echo "\033[38;5;16m   +> pipex Bonus \033[0m\033[38;5;42m [Done] \033[0m";
	

push:fclean
	@rm -rf outfile
	@git add .
	@read -p "Message:" message; \
	git commit -m "$$message"; \
	git push origin master

valgrind:fclean  bonus
	@rm -rf outfile
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./pipex srcs/pipex_bonus.c cat "grep index"  "grep int" "wc -l"  outfile

error:fclean bonus
	@rm -rf outfile
	@valgrind --leak-check=full --show-leak-kinds=all ./pipex srcs/pipex_bonus.c cat "grep index"  "grep int" "wc -l"  outfile

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
fclean : clean 
	@make fclean -C ./libft
	@rm -f $(NAME) $(LIBFT) 

re : fclean all
	@make re -C ./libft/

.PHONY : all $(NAME) clean fclean re