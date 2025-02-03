/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:37:59 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 15:42:04 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void    free_stack(t_list *stack)
{
    t_list *temp;

    while (stack)
    {
        temp = stack->next;
        free(stack->content);
        free(stack);
        stack = temp;
    }
}
