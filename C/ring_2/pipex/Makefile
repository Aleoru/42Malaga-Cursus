# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 18:44:34 by aoropeza          #+#    #+#              #
#    Updated: 2022/09/09 18:44:36 by aoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRC		= pipex.c pipex_utils.c pipex_split_utils.c pipex_childs.c pipex_free.c \
		pipex_error.c
OBJS	= $(SRC:.c=.o)
INC		= -I ./
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf

BOLD	= \033[1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) && printf "$(GREEN)$(BOLD)Pipex ready!\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
