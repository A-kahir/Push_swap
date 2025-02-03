/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:54:51 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 18:28:28 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		}
		if (s1[i] != s2[i])
		{
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		}
		i++;
	}
	return (0);
}