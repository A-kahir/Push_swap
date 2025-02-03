CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main_bonus.c func_rules1_bonus.c ft_free_stack_bonus.c ft_atoi_bonus.c \
		get_next_line_bonus.c ft_strlen_bonus.c ft_strcmp_bonus.c \
		get_next_line_utils_bonus.c ft_conditions_bonus.c ft_split_bonus.c 

OBJS = $(SRCS:.c=.o)

HEADER = ft_push_swap.h

NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o checker_bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) checker_bonus

re: fclean all

.PHONY: clean

