/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:22:03 by akahir            #+#    #+#             */
/*   Updated: 2025/01/19 18:36:55 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_conditions(int *stack_a, int size_a)
{
    int i;
    int j;
    int cantinue;

    i = 0;
    while (i < size_a)
    {
        j = i + 1;
        while (j < size_a)
        {
            if (stack_a[i] == stack_a[j])
                cantinue = 1;
            j++;
        }
        i++;
    }
    return (cantinue);
}

