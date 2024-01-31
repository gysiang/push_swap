LIBFT_PATH	= ./libraries/libft
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

SRC_FILES		= $(addprefix $(SRC_DIR)/, \
					main.c \
					init_stack.c \
					check_inputs.c \
					free.c \
					lst_utils.c \
					utils.c \
					commands.c \
					commands1.c \
					sort_algo.c \
					sort_algo1.c)

NAME			= push_swap

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@echo "Building ft_printf.."
	@make -C $(PRINTF_PATH)

OBJECTS			= $(SRC_FILES:.c=.o)

#Targets

all: 		$(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(INCLUDES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
