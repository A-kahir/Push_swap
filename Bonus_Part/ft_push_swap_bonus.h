#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_list
{
    int         *content;
    int         index;
    struct s_list *next;
} t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//bonus functions :
int main(int argc, char **argv);

//utils functions :
int is_sorted(t_list *stack);

//rules functions :
void	swap(t_list **stack, int *count);
void	swap_both(t_list **stack_a, t_list **stack_b, int *count);
void	push(t_list **from, t_list **to, int *count);
void	rotate(t_list **stack, int *count);
void	rotate_both(t_list **stack_a, t_list **stack_b, int *count);
void	reverse_rotate(t_list **stack, int *count);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, int *count);

//helper functions :
char	*get_next_line(int fd);
int	ft_atoi(char *str);
int ft_strcmp(const char *s1, const char *s2);
void free_stack(t_list *stack);
t_list *create_node(int content);

#endif
