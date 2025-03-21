/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:32:08 by akahir            #+#    #+#             */
/*   Updated: 2025/02/14 19:32:08 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if ((*str == '-' || *str == '+'))
	{
		if (!ft_isdigit(*(str + 1)))
			return (write(2, "Error\n", 6), exit(1), 0);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (write(2, "Error\n", 6), exit(1), 0);
		str++;
	}
	return (1);
}

int	ft_double_nb(t_list *stack_a)
{
	t_list	*current;
	t_list	*checker;

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

int	spaces_and_tabs(char *arg)
{
	char	*start;
	char	*end;
	char	*dest;

	start = arg;
	dest = arg;
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

int	ft_already_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
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
