/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_back_to_A.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:35:05 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 15:22:09 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void p_back_to_A(t_list **stack_b, t_list **stack_a, int len, int i, int *count)
{
    if (i <= (len / 2))
    {
        while (i > 0)
        {
            rotate(stack_b, "rb", count);
            i--;
        }
    }
    else
    {
        while (i < len)
        {
            reverse_rotate(stack_b, "rrb", count);
            i++;
        }
    }
    push(stack_b, stack_a, "pa", count);
}
