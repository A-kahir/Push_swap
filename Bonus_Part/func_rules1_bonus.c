/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rules1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:38:47 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 21:40:00 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

void swap(t_list **stack, int *count)
{
    t_list *first;
    t_list *second;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    (*count)++;
}

void swap_both(t_list **stack_a, t_list **stack_b, int *count)
{
    swap(stack_a, count);
    swap(stack_b,count);
    (*count)++;
}

void push(t_list **from, t_list **to, int *count)
{
    t_list *temp;

    if (*from == NULL)
        return;
    temp = *from;
    *from = (*from)->next;
    temp->next = *to;
    *to = temp;
    (*count)++;
}

void rotate(t_list **stack, int *count)
{
    t_list *first;
    t_list *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    (*count)++;
}

void rotate_both(t_list **stack_a, t_list **stack_b, int *count)
{
    rotate(stack_a, count);
    rotate(stack_b, count);
    (*count)++;
}

void reverse_rotate(t_list **stack, int *count)
{
    t_list *last;
    t_list *second_last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    second_last = *stack;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
    (*count)++;
}

void reverse_rotate_both(t_list **stack_a, t_list **stack_b, int *count)
{
    reverse_rotate(stack_a, count);
    reverse_rotate(stack_b, count);
    (*count)++;
}
