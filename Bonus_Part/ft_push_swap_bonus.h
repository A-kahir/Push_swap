/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:38:28 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 21:40:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

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
#  define BUFFER_SIZE 1
# endif

//principale functions:
int main(int argc, char **argv);
void ft_push_swap(t_list **stack_a, t_list **stack_b, int *count);

//rules functions:
void	swap(t_list **stack,int *count);
void	swap_both(t_list **stack_a, t_list **stack_b, int *count);
void	push(t_list **from, t_list **to,int *count);
void	rotate(t_list **stack,int *count);
void	rotate_both(t_list **stack_a, t_list **stack_b, int *count);
void	reverse_rotate(t_list **stack,int *count);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, int *count);

//conditions functions:
int	is_valid_number(char *str);
int	ft_double_nb(t_list *stack_a);
void    ft_if_3(t_list *stack_a, int *count);
void    ft_if_4(t_list *stack_a, t_list *stack_b, int *count);
void    ft_if_5(t_list *stack_a, t_list *stack_b, int *count);

//helper functions:
void    free_stack(t_list *stack);
char	**ft_split(const char *s, char c);
int	ft_atoi(char *str);
int	ft_strlen(const char *str);
int stack_size(t_list *stack);
int ft_position_max(t_list *stack);
void p_back_to_A(t_list **stack_b, t_list **stack_a, int len, int i, int *count);
char	*get_next_line(int fd);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
#endif