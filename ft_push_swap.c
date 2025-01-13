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

int is_sorted(int *stack, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (stack[i] > stack[i + 1]) {
            return 1; // Return false if any element is greater than the next
        }
    }
    return 0; // Return true if the entire stack is sorted
}

void push_swap(int *stack_a, int *stack_b, int size_a, int size_b)
{
    while (!is_sorted(stack_a, size_a) || size_b > 0) {
        // Swap if the top two elements in stack_a are out of order
        if (size_a > 1 && stack_a[0] > stack_a[1]) {
            swap(stack_a, size_a, "sa");
        }
        // Swap if the top two elements in stack_b are out of order
        else if (size_b > 1 && stack_b[0] < stack_b[1]) {
            swap(stack_b, size_b, "sb");
        }
        // Push from B to A if necessary
        else if (size_b > 0 && (size_a == 0 || stack_b[0] < stack_a[0])) {
            push(stack_b, stack_a, &size_b, &size_a, "pa");
        }
        // Push from A to B if A is not sorted
        else if (!is_sorted(stack_a, size_a)) {
            push(stack_a, stack_b, &size_a, &size_b, "pb");
        }
        // Rotate if it improves sorting
        else if (stack_a[0] > stack_a[size_a - 1]) {
            rotate(stack_a, size_a, "ra");
        }
        // Reverse rotate if needed
        else {
            reverse_rotate(stack_a, size_a, "rra");
        }
    }

    // Print final state of stacks
    printf("Stack A:\n");
    for (int k = 0; k < size_a; k++)
        printf("stack_a[%d] = %d\n", k, stack_a[k]);
        
    printf("Stack B:\n");
    for (int l = 0; l < size_b; l++) // Corrected loop for stack_b
        printf("stack_b[%d] = %d\n", l, stack_b[l]);
}

/*
    while ((stack_a || stack_b))
    {
        if (stack_a[i] > stack_a[j])
        {
            swap(stack_a, size_a, "sa");
        }
        else if (stack_b[i] > stack_b[j])
        {
            swap(stack_b, size_a, "sb");
        }
        else if (stack_a[i] > stack_a[j] && stack_b[i] > stack_b[j])
        {
            swap_both(stack_a, stack_b, size_a, size_b);
        }
        if (stack_a[0] < stack_a[1])
        {
            push(stack_a, stack_b, &size_a, &size_b, "pa");
            i = 0;
            j = i + 1;
        }
        else if (stack_b[0] < stack_b[1])
        {
            push(stack_b, stack_a, &size_b, &size_a, "pb");
        }
        if (stack_a[0] > stack_a[size_a])
        {
            rotate(stack_a, size_a, "ra");
        }
        else if (stack_b[0] > stack_b[size_b])
        {
            rotate(stack_b, size_b, "rb");
        }
        else if (stack_a[0] > stack_a[size_a] && stack_b[0] > stack_b[size_b])
        {
            rotate_both(stack_a, stack_b, size_a, size_b);
        }
        i++;
        j = i + 1;
    }
*/