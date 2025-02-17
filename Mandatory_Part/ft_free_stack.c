/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:40 by akahir            #+#    #+#             */
/*   Updated: 2025/02/17 11:56:39 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack->content);
		free(stack);
		stack = temp;
	}
}
