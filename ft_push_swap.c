/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:48:39 by akahir            #+#    #+#             */
/*   Updated: 2025/01/09 20:49:02 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	push_swap(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if (stack_a[0] > stack_a[1] || stack_b[0] > stack_b[1])
	{
		if (stack_a[0] > stack_a[1] && stack_b[0] > stack_b[1])
			ft_SAB(stack_a, stack_b, size_a);
		else if (stack_a[0] > stack_a[1])
			ft_SAB(stack_a, NULL, size_a);
		else if (stack_b[0] > stack_b[1])
			ft_SAB(NULL, stack_b, size_a);
	}
	if (stack_a && stack_b)
	{
		if (stack_a && stack_b[0] == 0)
		{
			ft_PAB(stack_a, stack_b, size_a, size_b);
		}
	}
	return (1);
}
