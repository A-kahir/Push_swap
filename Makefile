CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_conditions.c ft_helper_func.c ft_push_swap.c funcs_rules1.c funcs_rules2.c main.c
OBJS = $(SRCS:.c=.o)

HEADERS = ft_push_swap.h

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
