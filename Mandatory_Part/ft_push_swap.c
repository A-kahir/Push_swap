/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:09:31 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 15:06:27 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void ft_indexing(t_list *stack_a)
{
    t_list *current;
    t_list *min_node;
    int i;
    int list_size = stack_size(stack_a);

    i = 0;
    while (i < list_size) 
    {
        min_node = NULL;
        current = stack_a;
        while (current) 
        {
            if (current->index == -1)
            {
                if (!min_node || *(current->content) < *(min_node->content))
                    min_node = current;
            }
            current = current->next;
        }
        if (!min_node)
            break;
        min_node->index = i++;
    }
}

int ft_pos_max(t_list *stack)
{
    int max = *(stack->content);
    int pos = 0, max_pos = 0;
    t_list *list = stack;
    while (list)
    {
        if (*(list->content) > max)
        {
            max = *(list->content);
            max_pos = pos;
        }
        list = list->next;
        pos++;
    }
    return (max_pos);
}

void ft_sort_more(t_list **stack_a, t_list **stack_b, int *count)
{
    int max_pos;
    int len;

    while (*stack_b)
    {
        max_pos = ft_position_max(*stack_b);
        len = stack_size(*stack_b);
        p_back_to_A(stack_b, stack_a, len, max_pos, count);
    }   
}

void ft_push_chunks(t_list **stack_a, t_list **stack_b, int chunk_size, int *count)
{
    int i = 0;

    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            push(stack_a, stack_b, "pb", count);
            i++;
        }
        else if ((*stack_a)->index <= (i + chunk_size))
        {
            push(stack_a, stack_b, "pb", count);
            rotate(stack_b, "rb", count);
            i++;
        }
        else
            rotate(stack_a, "ra", count);
    }
}

void ft_push_swap(t_list **stack_a, t_list **stack_b, int *count)
{
    int size;
    int chunk_size;
    
    ft_indexing(*stack_a);
    size = stack_size(*stack_a);
    if (size < 100)
        chunk_size = 16;
    else
        chunk_size = 32;
    if (size == 2)
    {
        if (*((*stack_a)->content) > *((*stack_a)->next->content))
            return (swap(stack_a, "sa", count));
    }
    if (size == 3)
        ft_if_3(*stack_a, count);
    else if (size == 4)
        ft_if_4(*stack_a, *stack_b, count);
    else if (size == 5)
        ft_if_5(*stack_a, *stack_b, count);
    else if (size > 5)
    {
        ft_push_chunks(stack_a, stack_b, chunk_size, count);
        ft_sort_more(stack_a, stack_b, count);
    }
}
