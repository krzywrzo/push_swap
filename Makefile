CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	algorithm/alg_utils.c algorithm/cost_utils.c algorithm/find_index.c algorithm/push_swap_utils.c algorithm/push_swap.c algorithm/strategies.c \
	stack_manipulate/push.c stack_manipulate/reverse_rotate.c stack_manipulate/rotate.c stack_manipulate/stack_manipulation_utils.c stack_manipulate/swap.c \
	stack_utils/create_stack.c stack_utils/stack_validate.c
OBJS = $(SRC:.c=.o)
NAME = push_swap
AR = ar rcs
LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIB_PATH) all

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re
