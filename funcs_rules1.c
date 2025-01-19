/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_rules1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:23:37 by akahir            #+#    #+#             */
/*   Updated: 2025/01/17 20:01:41 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int ft_check(const char *rule, char *ch)
{
    int i;

    i = 0;
    while (rule[i] != '\0')
    {
        if (rule[i] != ch[i])
        {
            return (0);
        }
        i++;
    }
    return (1);
}
void    swap(int *stack, int size, const char *rule)
{
    int tmp;

    if (size > 1)
    {
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
    }
	if (ft_check(rule, "sa"))
		write(1, "sa\n", 3);
	else if (ft_check(rule, "sb"))
		write(1, "sb\n", 3);
}

void    swap_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
    swap(stack_a, size_a, NULL);
    swap(stack_b, size_b, NULL);
	write(1, "ss\n", 3);
}

void    push(int *stack_from, int *stack_to, int *size_from, int *size_to, const char *rule)
{
    int i;
    
    if (*size_from > 0)
    {
        i = *size_to;
        while (i > 0)
        {
            stack_to[i] = stack_to[i - 1];
            i--;
        }
        stack_to[0] = stack_from[0];
        i = 0;
        while (i < *size_from - 1)
        {
            stack_from[i] = stack_from[i + 1];
            i++;
        }
        stack_from[*size_from - 1] = 0;
        (*size_to)++;
        (*size_from)--;
	    if (ft_check(rule, "pa"))
		    write(1, "pa\n", 3);
	    else if (ft_check(rule, "pb"))
	    	write(1, "pb\n", 3);
    }
}

void    rotate(int *stack, int size, const char *rule)
{
    int tmp;
    int i;

    if (size > 1)
    {
        tmp = stack[0];
        i = 0;
        while (i < size - 1)
        {
            stack[i] = stack[i + 1];
            i++;
        }
        stack[size - 1] = tmp;
	    if (ft_check(rule, "ra"))
		    write(1, "ra\n", 3);
	    else if (ft_check(rule, "rb"))
		    write(1, "rb\n", 3);
    }
}

void    rotate_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
    rotate(stack_a, size_a, NULL);
    rotate(stack_b, size_b, NULL);
	write(1, "rr\n", 3);
}

void    reverse_rotate(int *stack, int size, const char *rule)
{
    int tmp;
    int i;

    if (size > 1)
    {
        tmp = stack[size - 1];
        i = size - 1;
        while (i > 0)
        {
            stack[i] = stack[i - 1];
            i--;
        }
        stack[0] = tmp;
	    if (ft_check(rule, "rra"))
		    write(1, "rra\n", 4);
	    else if (ft_check(rule, "rrb"))
		    write(1, "rrb\n", 4);
    }
}

void    reverse_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b)
{
    reverse_rotate(stack_a, size_a, NULL);
    reverse_rotate(stack_b, size_b, NULL);
	write(1, "rrr\n", 4);
}
