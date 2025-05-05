CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c stack_utils/stack_manipulation.c stack_utils/stack_manipulation_utils.c stack_utils/create_stack.c stack_utils/stack_validate.c
OBJS = $(SRC:.c=.o)
NAME = push_swap
AR = ar rcs
LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a
HEADER = push_swap.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

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
