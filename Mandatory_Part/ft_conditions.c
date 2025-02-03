/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:26:11 by akahir            #+#    #+#             */
/*   Updated: 2025/01/31 15:35:04 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_valid_number(char *str)
{
    int i;
	
	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
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
