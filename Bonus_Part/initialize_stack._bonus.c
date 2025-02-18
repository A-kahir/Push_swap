/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack._bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:05:19 by akahir            #+#    #+#             */
/*   Updated: 2025/02/18 12:05:19 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static	int	process_argument(char *arg, t_list **stack_a)
{
	t_list	*new_node;
	t_list	*last;

	if ((spaces_and_tabs(arg) == 0))
		return (1);
	if (is_valid_number(arg) == 0)
		return (1);
	new_node = create_node(ft_atoi(arg));
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
	return (0);
}

int	initialize_stack(int argc, char **argv, t_list **stack_a)
{
	char	**split_args;
	int		i;
	int		j;

	*stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !split_args[0])
			return (write(2, "Error\n", 6), 1);
		j = 0;
		while (split_args[j])
		{
			if (process_argument(split_args[j], stack_a))
				return (write(2, "Error\n", 6), free_split(split_args), 1);
			j++;
		}
		free_split(split_args);
		i++;
	}
	return (0);
}
