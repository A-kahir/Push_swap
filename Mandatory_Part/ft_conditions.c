/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:26:11 by akahir            #+#    #+#             */
/*   Updated: 2025/02/05 16:51:46 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int is_valid_number(char *str)
{
    if (!str || *str == '\0')
        return (0);
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int ft_double_nb(t_list *stack_a)
{
	t_list *current;
	t_list *checker;

    current = stack_a;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (*(current->content) == *(checker->content))
                return (1);
            checker = checker->next;
        }
        current = current->next;
    }
    return (0);
}
int spaces_and_tabs(char *arg)
{
    char *start = arg;
    char *end;
    char *dest = arg;

    while (*start == ' ' || *start == '\t')
        start++;
    if (*start == '\0') 
        return (0);
    end = start;
    while (*end)
        end++;
    end--;
    while (end > start && (*end == ' ' || *end == '\t'))
        end--;
    while (start <= end)
        *dest++ = *start++;
    *dest = '\0';
    return (1);
}

int ft_sign(t_list *stack_a)
{
    t_list *temp = stack_a;

    while (temp)
    {
        int *content = temp->content;
        
        if (*content == '+' || *content == '-')
        {
            if (*content == '+' || *content == '-') 
                return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int ft_already_sorted(t_list *stack_a)
{
    t_list *temp = stack_a;

    if (!temp)
        return (1);
    while (temp->next)
    {
        if (*(int *)(temp->content) > *(int *)(temp->next->content))
            return (0);
        temp = temp->next;
    }
    return (1);
}
