/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:37:18 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:37:18 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				*content;
	int				index;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//bonus functions :
int		main(int argc, char **argv);
int		initialize_stack(int argc, char **argv, t_list **stack_a);
void	ex_inst(char **instructions, t_list **stack_a, t_list **stack_b);

//conditions functions :
int		is_sorted(t_list *stack);
int		is_valid_number(char *str);
int		ft_double_nb(t_list *stack_a);
int		spaces_and_tabs(char *arg);
int		ft_already_sorted(t_list *stack_a);

//rules functions :
void	swap(t_list **stack);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push(t_list **from, t_list **to);
void	rotate(t_list **stack);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);

//helper functions :
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_stack(t_list *stack);
t_list	*create_node(int content);
char	**ft_split(const char *s, char c);
void	free_split(char **split);
int		is_valid_instruction(char *instr);

#endif
