/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:24:39 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 15:22:22 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int stack_size(t_list *stack)
{
    int size = 0;
    while (stack != NULL)
    {
        size++;
        stack = stack->next;
    }
    return size;
}
