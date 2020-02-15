NAME 		=		libftprintf.a
CC			= 		gcc
CFLAGS 		= 		-I includes/ -Wall -Werror -Wextra
OBJ 		= 		$(SRC:.c=.o)

C_OK		=		"\033[35m"
C_GOOD		=		"\033[32m"
C_NO		=		"\033[00m"

SUCCESS		=		$(C_GOOD)SUCCESS$(C_NO)
OK			=		$(C_OK)OK$(C_NO)

SRC =	format_parse.c ft_printf.c numeric_helpers.c print_base.c \
	print_int.c print_symbolic.c print_unsigned.c

all: $(NAME)

%.o: %.c
	@printf "[ft_printf] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[ft_printf] Compiling [:.]\r"

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "[ft_printf] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

re: fclean all

.PHONY: all clean fclean re test
