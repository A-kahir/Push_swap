/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:58:27 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 20:47:19 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_if_3(t_list *stack_a, int *count)
{
    int a;
    int b;
    int c;

    a = *(int *)(stack_a->content);
    b = *(int *)(stack_a->next->content);
    c = *(int *)(stack_a->next->next->content);
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
    int a;
    int b;
    int c;
    int d;

    if (stack_a->next->next->next->next != NULL)
        return;
    a = *(int *)(stack_a->content);
    b = *(int *)(stack_a->next->content);
    c = *(int *)(stack_a->next->next->content);
    d = *(int *)(stack_a->next->next->next->content);
    if (a == 0)
        push(&stack_a, &stack_b, "pb", count);
    else if (b == 0)
    {
        swap(&stack_a, "sa", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (c == 0)
    {
        rotate(&stack_a, "ra", count);
        rotate(&stack_a, "ra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (d == 0)
    {
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    ft_if_3(stack_a, count);
    push(&stack_b, &stack_a, "pa", count);
}

void ft_if_5(t_list *stack_a, t_list *stack_b, int *count)
{
    int a;
    int b;
    int c;
    int d;
    
    if (stack_a->next->next->next->next->next != NULL)
        return;
    a = *(int *)(stack_a->content);
    b = *(int *)(stack_a->next->content);
    c = *(int *)(stack_a->next->next->content);
    d = *(int *)(stack_a->next->next->next->content);
    // e = *(int *)(stack_a->next->next->next->next->content);
    
    if (a == 0)
        push(&stack_a, &stack_b, "pb", count);
    else if (b == 0)
    {
        swap(&stack_a, "sa", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (c == 0)
    {
        rotate(&stack_a, "ra", count);
        rotate(&stack_a, "ra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (d == 0)
    {
        reverse_rotate(&stack_a, "rra", count);
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    
    if (a == 1)
        push(&stack_a, &stack_b, "pb", count);
    else if (b == 1)
    {
        swap(&stack_a, "sa", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (c == 1)
    {
        rotate(&stack_a, "ra", count);
        rotate(&stack_a, "ra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    else if (d == 1)
    {
        reverse_rotate(&stack_a, "rra", count);
        reverse_rotate(&stack_a, "rra", count);
        push(&stack_a, &stack_b, "pb", count);
    }
    
    ft_if_3(stack_a, count);
    
    if (stack_b && stack_b->next && *(int *)(stack_b->content) > *(int *)(stack_b->next->content))
        swap(&stack_b, "sb", count);
    
    push(&stack_b, &stack_a, "pa", count);
    push(&stack_b, &stack_a, "pa", count);
}