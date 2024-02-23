LIBFT_PATH	= ./libraries/libft
LIBFT		= $(LIBFT_PATH)/libft.a

PRINTF_PATH		= ./libraries/printf
PRINTF			= $(PRINTF_PATH)/libftprintf.a

# Compiler and Flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES_DIR	= includes
SRC_DIR			= srcs/push_swap
BONUS_DIR		= srcs/checker
BONUS			= checker

LIBS			= -L$(LIBFT_PATH) -lft \
				-L$(PRINTF_PATH) -lftprintf

SRC_FILES1		= $(addprefix $(SRC_DIR)/, \
					main.c)

SRC_FILES2		= $(addprefix $(SRC_DIR)/, \
					init_stack.c \
					check_inputs.c \
					free.c \
					lst_utils.c \
					utils.c \
					commands.c \
					commands1.c \
					commands2.c \
					commands3.c \
					sort_three.c \
					sort_five.c \
					turk_sort.c)

BONUS_FILES		=	$(BONUS_DIR)/checker.c \
					$(BONUS_DIR)/checker_algo.c	\
					$(BONUS_DIR)/checker_algo1.c \
					libraries/getnextline/get_next_line.c

NAME			= push_swap
BONUS_NAME		= checker

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@echo "Building ft_printf.."
	@make -C $(PRINTF_PATH)

OBJECTS_1			= $(SRC_FILES1:.c=.o)
OBJECTS_2			= $(SRC_FILES2:.c=.o)

BONUS_OBJECTS	= $(BONUS_FILES:.c=.o)

#Targets

all: 		$(NAME) $(BONUS)

$(NAME): $(LIBFT) $(PRINTF) $(INCLUDES) $(OBJECTS_1) $(OBJECTS_2)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS_1) $(OBJECTS_2) $(LIBS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(PRINTF) $(INCLUDES) $(OBJECTS_2) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS_2) $(BONUS_OBJECTS) $(LIBS) -o $(BONUS_NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)
	rm -f $(BONUS_OBJECTS)

re: fclean all

.PHONY: all clean fclean re bonus
