/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:22:32 by akahir            #+#    #+#             */
/*   Updated: 2025/01/07 18:22:33 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int find_best_position(int *stack_a, int size_a, int value)
{
    int pos = 0;
    int i = 0;

    while (i < size_a)
    {
        if (value < stack_a[i] && 
            (i == 0 || value > stack_a[i - 1]))
        {
            pos = i;
            break;
        }
        i++;
    }
    if (i == size_a && value > stack_a[size_a - 1])
        pos = size_a;
    return pos;
}

void    push_swap(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int i;
    int min;
    int pos_min;
    int steps;
    int half;
    int best_pos;

    while (size_a > 3)
    {
        i = 0;
        min = stack_a[0];
        pos_min = 0;
        while (i < size_a)
        {
            if (stack_a[i] < min)
            {
                min = stack_a[i];
                pos_min = i;
            }
            i++;
        }
        steps = 0;
        half = size_a / 2;
        if (pos_min <= half)
        {
            while (steps < pos_min)
            {
                rotate(stack_a, size_a, "ra");
                steps++;
            }
        }
        else
        {
            while (steps < size_a - pos_min)
            {
                reverse_rotate(stack_a, size_a, "rra");
                steps++;
            }
        }
        push(stack_a, stack_b, &size_a, &size_b, "pb");
    }
    if (size_a == 2)
    {
        if (stack_a[0] > stack_a[1])
            swap(stack_a, size_a, "sa");
    }
    else if (size_a == 3)
    {
        if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2] && stack_a[0] < stack_a[2])
            swap(stack_a, size_a, "sa");
        else if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
        {
            swap(stack_a, size_a, "sa");
            reverse_rotate(stack_a, size_a, "rra");
        }
        else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2] && stack_a[0] > stack_a[2])
            rotate(stack_a, size_a, "ra");
        else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2] && stack_a[0] < stack_a[2])
        {
            swap(stack_a, size_a, "sa");
            rotate(stack_a, size_a, "ra");
        }
        else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2] && stack_a[0] > stack_a[2])
            reverse_rotate(stack_a, size_a, "rra");
    }
    while (size_b > 0)
    {
        best_pos = find_best_position(stack_a, size_a, stack_b[0]);
        steps = 0;

        if (best_pos <= size_a / 2)
        {
            while (steps++ < best_pos)
                rotate(stack_a, size_a, "ra");
        }
        else
        {
            while (steps++ < size_a - best_pos)
                reverse_rotate(stack_a, size_a, "rra");
        }
        push(stack_b, stack_a, &size_b, &size_a, "pa");
    }
}
