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

static	void	last_result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static int	ft_read(char **rules)
{
	char	*instruction;
	char	*temp;
	char	*store;

	store = ft_strdup("");
	if (!store)
		return (write(2, "Error\n", 6), 1);
	instruction = get_next_line(0);
	while (instruction)
	{
		temp = store;
		store = ft_strjoin(store, instruction);
		free(temp);
		free(instruction);
		if (!store)
			return (write(2, "Error\n", 6), 1);
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
	if (!instructions)
		return (write(2, "Error\n", 6), free_stack(stack_a), 1);
	ex_inst(instructions, &stack_a, &stack_b);
	free(instructions);
	last_result(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
