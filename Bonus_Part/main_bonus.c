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

static	void	last_result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static	int	process_instruction(char **store, char *instruction)
{
	char	*temp;

	if (instruction[0] == '\n' || !is_valid_instruction(instruction))
		return (write(2, "Error\n", 6), free(instruction), free(*store), 1);
	temp = *store;
	if (ft_strlen(*store) > 0)
		*store = ft_strjoin(*store, "\n");
	else
		*store = ft_strdup("");
	free(temp);
	if (!*store)
		return (write(2, "Error\n", 6), free(instruction), 1);
	temp = *store;
	*store = ft_strjoin(*store, instruction);
	free(temp);
	free(instruction);
	if (!*store)
		return (write(2, "Error\n", 6), 1);
	return (0);
}

static	int	ft_read(char **rules)
{
	char	*instruction;
	char	*store;

	store = ft_strdup("");
	if (!store)
		return (write(2, "Error\n", 6), 1);
	instruction = get_next_line(0);
	while (instruction)
	{
		if (process_instruction(&store, instruction))
			return (1);
		instruction = get_next_line(0);
	}
	*rules = store;
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*rules;
	char	**instructions;

	if (argc < 2)
		return (1);
	stack_b = NULL;
	if (initialize_stack(argc, argv, &stack_a))
		return (1);
	if ((ft_double_nb(stack_a) == 1))
		return (write(2, "Error\n", 6), free_stack(stack_a), 1);
	if (ft_read(&rules))
		return (free_stack(stack_a), 1);
	instructions = ft_split(rules, '\n');
	free(rules);
	ex_inst(instructions, &stack_a, &stack_b);
	free(instructions);
	last_result(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
