/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:27 by akahir            #+#    #+#             */
/*   Updated: 2025/02/05 14:16:15 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_if_3(t_list *stack_a, int *count)
{
    int a;
    int b;
    int c;

    a = *(stack_a->content);
    b = *(stack_a->next->content);
    c = *(stack_a->next->next->content);
    if (a > b && b < c && a < c)
        swap(&stack_a, "sa", count);
    else if (a > b && b > c)
    {
        swap(&stack_a, "sa", count);
        reverse_rotate(&stack_a, "rra", count);
    }
    else if (a > c && b < c)
        rotate(&stack_a, "ra", count);
    else if (a < b && b > c && a > c)
        reverse_rotate(&stack_a, "rra", count);
    else if (a > b && b < c && a > c)
    {
        swap(&stack_a, "sa", count);
        rotate(&stack_a, "ra", count);
    }
}
void ft_if_4(t_list *stack_a, t_list *stack_b, int *count)
{
    int min;
    t_list *temp;

    min = *(stack_a->content);
    temp = stack_a;
    while (temp)
    {
        if (*(temp->content) < min)
            min = *(temp->content);
        temp = temp->next;
    }
    while (*(stack_a->content) != min)
    {
        if (*(stack_a->next->content) == min)
            swap(&stack_a, "sa", count);
        else if (*(stack_a->next->next->content) == min)
        {
            rotate(&stack_a, "ra", count);
            rotate(&stack_a, "ra", count);
        }
        else
            reverse_rotate(&stack_a, "rra", count);
    }
    push(&stack_a, &stack_b, "pb", count);
    ft_if_3(stack_a, count);
    push(&stack_b, &stack_a, "pa", count);
}

void ft_if_5(t_list *stack_a, t_list *stack_b, int *count)
{
    int min;
    t_list *temp;

    for (int i = 0; i < 2; i++)
    {
        min = *(stack_a->content);
        temp = stack_a;
        while (temp)
        {
            if (*(temp->content) < min)
                min = *(temp->content);
            temp = temp->next;
        }
        while (*(stack_a->content) != min)
        {
            if (*(stack_a->next->content) == min)
                swap(&stack_a, "sa", count);
            else if (*(stack_a->next->next->content) == min)
            {
                rotate(&stack_a, "ra", count);
                rotate(&stack_a, "ra", count);
            }
            else if (*(stack_a->next->next->next->content) == min)
            {
                reverse_rotate(&stack_a, "rra", count);
                reverse_rotate(&stack_a, "rra", count);
            }
            else
                rotate(&stack_a, "ra", count);
        }
        push(&stack_a, &stack_b, "pb", count);
    }
    ft_if_3(stack_a, count);
    if (stack_b && stack_b->next && 
        *(stack_b->content) < *(stack_b->next->content))
        swap(&stack_b, "sb", count);
    push(&stack_b, &stack_a, "pa", count);
    push(&stack_b, &stack_a, "pa", count);
}
