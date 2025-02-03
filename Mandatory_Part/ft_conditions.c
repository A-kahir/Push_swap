/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:26:11 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 20:50:38 by akahir           ###   ########.fr       */
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
