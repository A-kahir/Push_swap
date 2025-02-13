/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rules1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:59:31 by akahir            #+#    #+#             */
/*   Updated: 2025/01/31 15:56:00 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void swap(t_list **stack, const char *rule, int *count)
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
    write(1, rule, ft_strlen(rule));
    write(1, "\n", 1);
    (*count)++;
}

void swap_both(t_list **stack_a, t_list **stack_b, int *count)
{
    swap(stack_a, "sa", count);
    swap(stack_b, "sb", count);
    write(1, "ss\n", 3);
    (*count)++;
}

void push(t_list **from, t_list **to, const char *rule, int *count)
{
    t_list *temp;

    if (*from == NULL)
        return;
    temp = *from;
    *from = (*from)->next;
    temp->next = *to;
    *to = temp;
    write(1, rule, ft_strlen(rule));
    write(1, "\n", 1);
    (*count)++;
}
