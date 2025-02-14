/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rules1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:38:44 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:38:44 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void	swap(t_list **stack, int *count)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	(*count)++;
}

void	swap_both(t_list **stack_a, t_list **stack_b, int *count)
{
	swap(stack_a, count);
	swap(stack_b, count);
	(*count)++;
}

void	push(t_list **from, t_list **to, int *count)
{
	t_list	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	(*count)++;
}
