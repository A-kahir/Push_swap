/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:45:10 by akahir            #+#    #+#             */
/*   Updated: 2025/01/09 20:49:53 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int main(int argc, char **argv);
int	push_swap(int *stack_a, int *stack_b, int size_a, int size_b);

// functions rules -1-:
void	ft_SAB(int *sa, int *sb, int size_a);
void    ft_PAB(int *pa, int *pb, int size_a, int size_b);
void	ft_RAB(int *ra, int *rb, int size_a, int size_b);
// helper func:

#endif