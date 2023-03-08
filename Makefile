CFLAGS = -Wall -Werror -Wextra
SRCS = main.c inputs.c swap.c push.c rotate.c reverse_rotate.c tri.c push_swap_utils.c actions.c actions_lists.c distance.c
OBJS = $(SRCS:.c=.o)
LIBS = libft/libft.a
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)	
	$(CC) $(LIBS) $(OBJS) -o $(NAME)

$(LIBS):
	make -C libft
	make bonus -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
	
