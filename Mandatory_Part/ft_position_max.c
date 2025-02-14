/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:28:32 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 18:52:08 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_position_max(t_list *stack)
{
	int		max;
	int		pos;
	int		max_pos;
	t_list	*list;

	max = *(stack->content);
	pos = 0;
	max_pos = 0;
	list = stack;
	while (list)
	{
		if (*(list->content) > max)
		{
			max = *(list->content);
			max_pos = pos;
		}
		list = list->next;
		pos++;
	}
	return (max_pos);
}
