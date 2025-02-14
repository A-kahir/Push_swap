/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:45:33 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:45:33 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static	int	exe_instr(char *instr, t_list **stk_a, t_list **stk_b, int *count)
{
	if (!ft_strcmp(instr, "sa\n"))
		swap(stk_a, count);
	else if (!ft_strcmp(instr, "sb\n"))
		swap(stk_b, count);
	else if (!ft_strcmp(instr, "ss\n"))
		swap_both(stk_a, stk_b, count);
	else if (!ft_strcmp(instr, "pa\n"))
		push(stk_b, stk_a, count);
	else if (!ft_strcmp(instr, "pb\n"))
		push(stk_a, stk_b, count);
	else if (!ft_strcmp(instr, "ra\n"))
		rotate(stk_a, count);
	else if (!ft_strcmp(instr, "rb\n"))
		rotate(stk_b, count);
	else if (!ft_strcmp(instr, "rr\n"))
		rotate_both(stk_a, stk_b, count);
	else if (!ft_strcmp(instr, "rra\n"))
		reverse_rotate(stk_a, count);
	else if (!ft_strcmp(instr, "rrb\n"))
		reverse_rotate(stk_b, count);
	else if (!ft_strcmp(instr, "rrr\n"))
		reverse_rotate_both(stk_a, stk_b, count);
	else
		return (0);
	return (1);
}

static	int	initialize_stack(int argc, char **argv, t_list **stack_a)
{
	t_list	*new_node;
	t_list	*last;
	int		i;

	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if ((is_valid_number(argv[i]) == 0) || (spaces_and_tabs(argv[i]) == 0))
			return (write(2, "Error\n", 6), 1);
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
			return (free_stack(*stack_a), 1);
		if (!*stack_a)
			*stack_a = new_node;
		else
		{
			last = *stack_a;
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;
	int		count;

	if (argc < 2)
		return (1);
	stack_b = NULL;
	count = 0;
	if (initialize_stack(argc, argv, &stack_a))
		return (1);
	if ((ft_double_nb(stack_a) == 1) || (ft_sign(stack_a) == 1))
		return (write(2, "Error\n", 6), free_stack(stack_a), 1);
	if (ft_already_sorted(stack_a))
		return (write(1, "OK\n", 3), free_stack(stack_a), 0);
	while (instruction = get_next_line(0))
	{
		if (!exe_instr(instruction, &stack_a, &stack_b, &count))
			return (write(2, "Error\n", 6), free(instruction),
				free_stack(stack_a), free_stack(stack_b), 1);
		free(instruction);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
