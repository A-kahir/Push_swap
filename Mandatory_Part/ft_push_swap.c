/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:09:31 by akahir            #+#    #+#             */
/*   Updated: 2025/02/23 13:20:23 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	ft_indexing(t_list *stack_a)
{
	t_list	*current;
	t_list	*min_node;
	int		i;
	int		list_size;

	i = 0;
	list_size = stack_size(stack_a);
	while (i < list_size)
	{
		min_node = NULL;
		current = stack_a;
		while (current)
		{
			if (current->index == -1)
			{
				if (!min_node || *(current->content) < *(min_node->content))
					min_node = current;
			}
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = i++;
	}
}

static	void	ft_sort_more(t_list **stack_a, t_list **stack_b, int *count)
{
	int	max_pos;

	while (*stack_b)
	{
		max_pos = ft_position_max(*stack_b);
		p_back_to_a(stack_b, stack_a, max_pos, count);
	}
}

static	void	chunk(t_list **stk_a, t_list **stk_b, int size_ch, int *count)
{
	int	i;

	i = 0;
	while (*stk_a)
	{
		if ((*stk_a)->index <= i)
		{
			push(stk_a, stk_b, "pb", count);
			i++;
		}
		else if ((*stk_a)->index < (i + size_ch))
		{
			push(stk_a, stk_b, "pb", count);
			rotate(stk_b, "rb", count);
			i++;
		}
		else
			rotate(stk_a, "ra", count);
	}
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b, int *count)
{
	int	size;
	int	size_ch;

	ft_indexing(*stack_a);
	size = stack_size(*stack_a);
	if (size <= 100)
		size_ch = 16;
	else
		size_ch = 36;
	if (size == 2)
	{
		if (*((*stack_a)->content) > *((*stack_a)->next->content))
			return (swap(stack_a, "sa", count));
	}
	if (size == 3)
		ft_if_3(stack_a, count);
	else if (size == 4)
		ft_if_4(stack_a, stack_b, count);
	else if (size == 5)
		ft_if_5(stack_a, stack_b, count);
	else if (size > 5)
	{
		chunk(stack_a, stack_b, size_ch, count);
		ft_sort_more(stack_a, stack_b, count);
	}
}
