/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_rules1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:23:37 by akahir            #+#    #+#             */
/*   Updated: 2025/01/07 18:23:38 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <libc.h>


void ft_SAB(int *sa, int *sb)
{
    int temp_a;
    int temp_b;
    
	if (sa && sb == 0)
	{
    	temp_a = sa[0];
    	sa[0] = sa[1];
    	sa[1] = temp_a;
	}
	else if (sa == 0 && sb)
	{
		temp_b = sb[0];
    	sb[0] = sb[1];
    	sb[1] = temp_b;
	}
	else if (sa && sb)
	{
		temp_a = sa[0];
    	sa[0] = sa[1];
    	sa[1] = temp_a;
		temp_b = sb[0];
    	sb[0] = sb[1];
    	sb[1] = temp_b;
	}
}

// void	ft_PAB(int *pa, int *pb)
// {
// 	int *temp;

// 	if (pa && pb)
// 	{
// 		temp = pb[1];
// 		pa[]
// 	}
// }

// int main()
// {
// 	int pa[] = {4, 2, 5, 3};
// 	int pb[] = {1, 6, 7};

// 	ft_PAB();
// }
