/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:09 by akahir            #+#    #+#             */
/*   Updated: 2025/02/17 11:38:09 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	is_valid_instruction(char *instr)
{
	if (instr && instr[ft_strlen(instr) - 1] == '\n')
		instr[ft_strlen(instr) - 1] = '\0';
	return (
		!ft_strcmp(instr, "sa") || !ft_strcmp(instr, "sb")
		|| !ft_strcmp(instr, "ss") || !ft_strcmp(instr, "pa")
		|| !ft_strcmp(instr, "pb") || !ft_strcmp(instr, "ra")
		|| !ft_strcmp(instr, "rb") || !ft_strcmp(instr, "rr")
		|| !ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrb")
		|| !ft_strcmp(instr, "rrr")
	);
}

static	int	cantinue_exe(char *instr, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strcmp(instr, "ra"))
		rotate(stk_a);
	else if (!ft_strcmp(instr, "rb"))
		rotate(stk_b);
	else if (!ft_strcmp(instr, "rr"))
		rotate_both(stk_a, stk_b);
	else if (!ft_strcmp(instr, "rra"))
		reverse_rotate(stk_a);
	else if (!ft_strcmp(instr, "rrb"))
		reverse_rotate(stk_b);
	else if (!ft_strcmp(instr, "rrr"))
		reverse_rotate_both(stk_a, stk_b);
	else
		return (0);
	return (1);
}

int	exe_instr(char *instr, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strcmp(instr, "sa"))
		swap(stk_a);
	else if (!ft_strcmp(instr, "sb"))
		swap(stk_b);
	else if (!ft_strcmp(instr, "ss"))
		swap_both(stk_a, stk_b);
	else if (!ft_strcmp(instr, "pa"))
		push(stk_b, stk_a);
	else if (!ft_strcmp(instr, "pb"))
		push(stk_a, stk_b);
	else
		return (cantinue_exe(instr, stk_a, stk_b));
	return (1);
}

void	ex_inst(char **instructions, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (!exe_instr(instructions[i], stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			free(instructions[i]);
			free(instructions);
			free_stack(*stack_a);
			free_stack(*stack_b);
			exit(1);
		}
		free(instructions[i]);
		i++;
	}
}
