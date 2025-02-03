/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:27 by akahir            #+#    #+#             */
/*   Updated: 2025/02/01 17:24:26 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_if_3(t_list *stack_a, int *count)
{
    if (*(stack_a->content) > *(stack_a->next->content) && *(stack_a->next->content) > *(stack_a->next->next->content))
    {
        swap(&stack_a, "sa", count);
        reverse_rotate(&stack_a, "rra", count);
    }
    else if (*(stack_a->content) > *(stack_a->next->next->content) && *(stack_a->next->next->content) > *(stack_a->next->content))
        rotate(&stack_a, "ra", count);
    else if (*(stack_a->next->content) > *(stack_a->content) && *(stack_a->content) > *(stack_a->next->next->content))
        swap(&stack_a, "sa", count);
    else if (*(stack_a->next->content) > *(stack_a->next->next->content) && *(stack_a->next->next->content) > *(stack_a->content))
    {
        swap(&stack_a, "sa", count);
        rotate(&stack_a, "ra", count);
    }
    else if (*(stack_a->next->next->content) > *(stack_a->content) && *(stack_a->content) > *(stack_a->next->content))
        reverse_rotate(&stack_a, "rra", count);
}

static void cantinue_4(t_list *stack_a, int *count)
{
    if (stack_a->index > stack_a->next->index && stack_a->next->index > stack_a->next->next->index)
    {
        swap(&stack_a, "sa", count);
        reverse_rotate(&stack_a, "rra", count);
    }
    else if (stack_a->index > stack_a->next->next->index && stack_a->next->next->index > stack_a->next->index)
        rotate(&stack_a, "ra", count);
    else if (stack_a->next->index > stack_a->index && stack_a->index > stack_a->next->next->index)
        swap(&stack_a, "sa", count);
    else if (stack_a->next->index > stack_a->next->next->index && stack_a->next->next->index > stack_a->index)
    {
        swap(&stack_a, "sa", count);
        rotate(&stack_a, "ra", count);
    }
    else if (stack_a->next->next->index > stack_a->index && stack_a->index > stack_a->next->index)
        reverse_rotate(&stack_a, "rra", count);
}

void ft_if_4(t_list *stack_a, t_list *stack_b, int *count)
{
    if (stack_a->next->next->next->next == NULL)
    {
        if (stack_a->index == 0)
            push(&stack_a, &stack_b, "pb", count);
        else if (stack_a->next->index == 0)
        {
            swap(&stack_a, "sa", count);
            push(&stack_a, &stack_b, "pb", count);
        }
        else if (stack_a->next->next->index == 0)
        {
            rotate(&stack_a, "ra", count);
            rotate(&stack_a, "ra", count);
            push(&stack_a, &stack_b, "pb", count);
        }
        else if (stack_a->next->next->next->index == 0)
        {
            reverse_rotate(&stack_a, "rra", count);
            push(&stack_a, &stack_b, "pb", count);
        }
        cantinue_4(stack_a, count);
        push(&stack_b, &stack_a, "pa", count);
    }
}

static void cantinue_5(t_list *stack_a, t_list *stack_b, int *count)
{
    if (stack_size(stack_a) >= 5 && stack_a->next->next->next->next->index == 0)
    {
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    if (stack_a->index == 1)
        push(&stack_a, &stack_b, "pb", count);
    else if (stack_a->next->index == 1)
    {
        swap(&stack_a, "sa", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (stack_size(stack_a) >= 3 && stack_a->next->next->index == 1)
    {
        rotate(&stack_a, "ra", count);
        rotate(&stack_a, "ra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (stack_size(stack_a) >= 4 && stack_a->next->next->next->index == 1)
    {
        reverse_rotate(&stack_a, "rra", count);
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    ft_if_3(stack_a, count);
    if (stack_b && stack_b->next && stack_b->index < stack_b->next->index)
        swap(&stack_b, "sb", count);
}

void ft_if_5(t_list *stack_a, t_list *stack_b, int *count)
{
    if (stack_size(stack_a) < 5)
        return;
    if (stack_a->index == 0)
        push(&stack_a, &stack_b, "pb", count);
    else if (stack_a->next->index == 0)
    {
        swap(&stack_a, "sa", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (stack_a->next->next->index == 0)
    {
        rotate(&stack_a, "ra", count);
        rotate(&stack_a, "ra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (stack_a->next->next->next->index == 0)
    {
        reverse_rotate(&stack_a, "rra", count);
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    cantinue_5(stack_a, stack_b, count);
    push(&stack_b, &stack_a, "pa", count);
    push(&stack_b, &stack_a, "pa", count);
}


