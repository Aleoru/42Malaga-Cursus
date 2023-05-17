# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 18:44:34 by aoropeza          #+#    #+#              #
#    Updated: 2023/05/17 12:49:57 by aoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= horde
SRC		= main.cpp Zombie.cpp zombieHorde.cpp
OBJS	= $(SRC:.cpp=.o)
CC		= c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
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
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) && printf "$(GREEN)$(BOLD)An horde is coming!!\n$(RESET)"

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean :
	@$(RM) $(OBJS) && printf "$(YELLOW)All objects have been clean :)\n$(RESET)"

fclean : clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(NAME) $(GREEN)has been clean :)\n$(RESET)"

re : fclean all

.PHONY : all clean fclean re
