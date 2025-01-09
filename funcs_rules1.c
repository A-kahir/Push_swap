/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_rules1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:23:37 by akahir            #+#    #+#             */
/*   Updated: 2025/01/09 20:50:22 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_SAB(int *sa, int *sb, int size_a)
{
	int temp_a;
	int temp_b;

	if (sa && sb == 0)
	{
		temp_a = sa[0];
		sa[0] = sa[1];
		sa[1] = temp_a;
		write(1, "sa\n", 3);
	}
	if (sb && sa == 0)
	{
		temp_b = sb[0];
		sb[0] = sb[1];
		sb[1] = temp_b;
		write(1, "sb\n", 3);
	}
	if (sa && sb)
	{
		temp_a = sa[0];
		sa[0] = sa[1];
		sa[1] = temp_a;
		temp_b = sb[0];
		sb[0] = sb[1];
		sb[1] = temp_b;
		write(1, "ss\n", 3);
	}
}

void    ft_PAB(int *pa, int *pb, int size_a, int size_b)
{
	
}
void	ft_RAB(int *ra, int *rb, int size_a, int size_b)
{
	int temp;
	int i;

	if (ra && size_a > 1)
	{
		temp = ra[0];
		i = 0;
		while (++i < size_a)
			ra[i - 1] = ra[i];
		ra[size_a - 1] = temp;
		write(1, "ra\n", 3);
	}
	if (rb && size_b > 1)
	{
		temp = rb[0];
		i = 0;
		while (++i < size_b)
			rb[i - 1] = rb[i];
		rb[size_b - 1] = temp;
		write(1, "rb\n", 3);
	}
	if (ra && rb)
		write(1, "rr\n", 3);
}

