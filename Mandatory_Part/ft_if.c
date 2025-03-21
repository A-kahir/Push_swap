/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:27 by akahir            #+#    #+#             */
/*   Updated: 2025/02/24 13:48:35 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_if_3(t_list **stack_a, int *count)
{
	int	a;
	int	b;
	int	c;

	a = *((*stack_a)->content);
	b = *((*stack_a)->next->content);
	c = *((*stack_a)->next->next->content);
	if (a > b && b < c && a < c)
		swap(stack_a, "sa", count);
	else if (a > b && b > c)
	{
		rotate(stack_a, "ra", count);
		swap(stack_a, "sa", count);
	}
	else if (a > c && b < c)
		rotate(stack_a, "ra", count);
	else if (a < b && b > c && a > c)
		reverse_rotate(stack_a, "rra", count);
	else if ((a < b && b > c && a < c) || (a > b && b < c && a > c))
	{
		swap(stack_a, "sa", count);
		rotate(stack_a, "ra", count);
	}
}

void	move_min_to_top(t_list **stack_a, int min, int *count)
{
	while (*((*stack_a)->content) != min)
	{
		if (*((*stack_a)->next->content) == min)
			swap(stack_a, "sa", count);
		else if (*((*stack_a)->next->next->content) == min)
		{
			rotate(stack_a, "ra", count);
			rotate(stack_a, "ra", count);
		}
		else
			reverse_rotate(stack_a, "rra", count);
	}
}

static	int	find_min_pos(t_list **stack)
{
	t_list	*temp;
	int		min;
	int		min_pos;
	int		i;

	temp = *stack;
	min = *(temp->content);
	min_pos = 0;
	i = 0;
	while (temp)
	{
		if (*(temp->content) < min)
		{
			min = *(temp->content);
			min_pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_pos);
}

void	ft_if_4(t_list **stack_a, t_list **stack_b, int *count)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	if (min_pos == 1)
		swap(stack_a, "sa", count);
	else if (min_pos == 2)
	{
		rotate(stack_a, "ra", count);
		rotate(stack_a, "ra", count);
	}
	else if (min_pos == 3)
		reverse_rotate(stack_a, "rra", count);
	push(stack_a, stack_b, "pb", count);
	ft_if_3(stack_a, count);
	push(stack_b, stack_a, "pa", count);
}

void	ft_if_5(t_list **stack_a, t_list **stack_b, int *count)
{
	int		min;
	t_list	*temp;
	int		i;

	i = 0;
	while (i < 2)
	{
		temp = *stack_a;
		min = *(temp->content);
		while (temp)
		{
			if (*(temp->content) < min)
				min = *(temp->content);
			temp = temp->next;
		}
		move_min_to_top(stack_a, min, count);
		push(stack_a, stack_b, "pb", count);
		i++;
	}
	ft_if_3(stack_a, count);
	if (stack_b && (*stack_b)->next
		&& *((*stack_b)->content) < *((*stack_b)->next->content))
		swap(stack_b, "sb", count);
	push(stack_b, stack_a, "pa", count);
	push(stack_b, stack_a, "pa", count);
}
