NAME	= push_swap
LIBFT	= libft

INC		= -I ./ -I $(LIBFT)/inc
LFLAGS	= -L$(LIBFT) -lft
SRC		= push_swap.c
OBJS	= $(SRC:.c=.o)

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

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(INC) -o $(NAME) && printf "$(GREEN)$(BOLD)Let's swap_push- I mean, push_swap\n$(RESET)"

%o. : %.c
	@$(CC) -o $@ -c $< $(INC) && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJS) && printf "$(GREEN)$(BOLD)All objects cleaned! :)\n$(RESET)"
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re
