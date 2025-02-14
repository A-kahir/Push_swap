CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  Mandatory_Part/main.c Mandatory_Part/ft_free_stack.c Mandatory_Part/ft_split.c \
        Mandatory_Part/ft_atoi.c Mandatory_Part/ft_conditions.c Mandatory_Part/func_rules1.c \
        Mandatory_Part/ft_strlen.c Mandatory_Part/ft_push_swap.c Mandatory_Part/ft_if.c \
        Mandatory_Part/ft_stack_size.c Mandatory_Part/ft_p_back_to_a.c \
        Mandatory_Part/ft_position_max.c Mandatory_Part/func_rules2.c 

SRCB = Bonus_Part/main_bonus.c Bonus_Part/get_next_line.c \
       Bonus_Part/get_next_line_utils.c Bonus_Part/ft_atoi_bonus.c \
	   Bonus_Part/func_rules1_bonus.c Bonus_Part/ft_conditions_bonus.c \
	   Bonus_Part/helper_func.c 

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

HEADER = Mandatory_Part/ft_push_swap.h
HEADER_BONUS = Bonus_Part/ft_push_swap_bonus.h

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJB): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re