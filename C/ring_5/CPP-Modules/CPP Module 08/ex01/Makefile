# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 18:44:34 by aoropeza          #+#    #+#              #
#    Updated: 2024/01/03 18:46:42 by aoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= easyfind
SRC		= main.cpp Span.cpp
OBJS	= $(SRC:.cpp=.o)
CC		= c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

UNAME	= $(shell uname -s)

ifeq ($(UNAME), Linux)
CPPFLAGS = -Wall -Wextra
$(warning Linux detected! Disabling -Werror and -std=c++98...)
endif

BOLD	= \033[1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) && printf "$(GREEN)$(BOLD)Easy find\n$(RESET)"

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean :
	@$(RM) $(OBJS) && printf "$(YELLOW)All objects have been clean :)\n$(RESET)"

fclean : clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(NAME) $(GREEN)has been clean :)\n$(RESET)"

re : fclean all

.PHONY : all clean fclean re
