/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rules2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:42:29 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:42:29 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	rotate(t_list **stack, int *count)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	(*count)++;
}

void	rotate_both(t_list **stack_a, t_list **stack_b, int *count)
{
	rotate(stack_a, count);
	rotate(stack_b, count);
	(*count)++;
}

void	reverse_rotate(t_list **stack, int *count)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	(*count)++;
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b, int *count)
{
	reverse_rotate(stack_a, count);
	reverse_rotate(stack_b, count);
	(*count)++;
}
