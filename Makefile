NAME = push_swap
FLAG =	-Wall -Wextra -Werror
SRCS = check_add.c fill_a.c push.c rev_rotate.c\
		issorted.c main.c radix_sort.c rotate.c swap.c\
		stack_func.c sort4_5.c sort3.c ft_free.c\
		ft_atoi.c ft_split.c ft_put.c

OBJS =		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			gcc $(FLAG) $(OBJS) -o $(NAME)

clean: $(OBJS)
		rm -rf $(OBJS)

fclean: clean
		rm -rf push_swap

re: all clean

.PHONY: all clean fclean re