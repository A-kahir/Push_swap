/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:50:02 by akahir            #+#    #+#             */
/*   Updated: 2025/02/18 20:36:32 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	void	check_overflow(int sign, long result)
{
	if ((sign == 1 && (result * sign) > 2147483647)
		|| (sign == -1 && (result * sign) < -2147483648))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		check_overflow(sign, result);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((int)(result * sign));
}
