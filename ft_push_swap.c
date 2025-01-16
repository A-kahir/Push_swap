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

void    push_swap(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int i;
    int min;
    int min_pos;
    int steps;
    int half;

    while (size_a > 3)
    {
        // Find minimum
        i = 0;
        min = stack_a[0];
        min_pos = 0;
        while (i < size_a)
        {
            if (stack_a[i] < min)
            {
                min = stack_a[i];
                min_pos = i;
            }
            i++;
        }

        // Calculate steps and half
        steps = 0;
        half = size_a / 2;

        // Move minimum to top using rotate or reverse_rotate
        if (min_pos <= half)
        {
            while (steps < min_pos)
            {
                rotate(stack_a, size_a, "ra");
                steps++;
            }
        }
        else
        {
            while (steps < size_a - min_pos)
            {
                reverse_rotate(stack_a, size_a, "rra");
                steps++;
            }
        }
        push(stack_a, stack_b, &size_a, &size_b, "pb");
    }

    // Sort remaining 3 elements in stack_a
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

    // Push all elements back from B to A
    while (size_b > 0)
    {
        push(stack_b, stack_a, &size_b, &size_a, "pa");
    }
    printf("Stack A:\n");
    for (int k = 0; k < size_a; k++)
        printf("stack_a[%d] = %d\n", k, stack_a[k]);
        
    printf("Stack B:\n");
    for (int l = 0; l < size_b; l++) // Corrected loop for stack_b
        printf("stack_b[%d] = %d\n", l, stack_b[l]);
}


/*
    printf("Stack A:\n");
    for (int k = 0; k < size_a; k++)
        printf("stack_a[%d] = %d\n", k, stack_a[k]);
        
    printf("Stack B:\n");
    for (int l = 0; l < size_b; l++) // Corrected loop for stack_b
        printf("stack_b[%d] = %d\n", l, stack_b[l]);
*/