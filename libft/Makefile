# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 15:54:55 by mmasstou          #+#    #+#              #
#    Updated: 2022/03/31 18:40:16 by mmasstou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CFLAGS 		= -Wall -Wextra -Werror 
CC = cc
SRCS =	ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memset.c \
		ft_memmove.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_split.c \

BONUS = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
	


OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "\x1b[36m   +> LIBFT \033[0m\033[38;5;42m [Done] \033[0m";
	
bonus: $(B_OBJS) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(B_OBJS)
	@echo "\x1b[36m   +> LIBFT \033[0m\033[38;5;42m [Done] \033[0m";
	
%.o:%.c libft.h 
		@${CC} ${CFLAGS} -I . -o $@ -c $<
		@printf "\x1b[36m   +>\033[0m compiling \033[38;5;42m$< \033[0m\n"

clean:
	@rm -f *.o
	
fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[36m   +> Clean LIBFT \033[0m\033[38;5;42m [Done] \033[0m";

re: fclean all

.PHONY : all bonus clean fclean re