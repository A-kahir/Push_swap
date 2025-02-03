CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_free_stack.c ft_split.c ft_atoi.c ft_conditions.c func_rules1.c ft_strlen.c ft_push_swap.c ft_if.c ft_stack_size.c ft_p_back_to_A.c ft_position_max.c
OBJS = $(SRCS:.c=.o)

HEADER = ft_push_swap.h

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
