LIBFT_PATH	= ./libraries/libraries
LIBFT		= $(LIBFT_PATH)/libft.a

PRINTF_PATH		= ./libraries/printf
PRINTF			= $(PRINTF_PATH)/libftprintf.a

# Compiler and Flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES_DIR	= includes
SRC_DIR			= srcs

LIBS			= -L$(LIBFT_PATH) -lft \
				-L$(PRINTF_PATH) -lftprintf

SRC FILES		= $(addprefix $(SRC_DIR)
					main.c \
					)

NAME			= push_swap

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@echo "Building ft_printf.."
	@make -C $(PRINTF_PATH)

OBJECTS			= $(SRC_FILES:.c=.o)

$(NAME): $(LIBFT) $(PRINTF) $(INCLUDES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
