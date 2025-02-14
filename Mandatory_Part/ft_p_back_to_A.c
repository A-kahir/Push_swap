/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_back_to_A.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:24:35 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:27:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	p_back_to_a(t_list **stk_b, t_list **stk_a, int max, int *count)
{
	int	len;

	len = stack_size(*stk_b);
	if (max <= (len / 2))
	{
		while (max > 0)
		{
			rotate(stk_b, "rb", count);
			max--;
		}
	}
	else
	{
		while (max < len)
		{
			reverse_rotate(stk_b, "rrb", count);
			max++;
		}
	}
	push(stk_b, stk_a, "pa", count);
}
