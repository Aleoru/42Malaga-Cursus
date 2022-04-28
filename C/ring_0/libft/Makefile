# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:18:48 by aoropeza          #+#    #+#              #
#    Updated: 2022/04/27 20:10:45 by aoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= *.c
OBJS	= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRC)
	ar cr $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(NAME)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY: all clean fclean re
