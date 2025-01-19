/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:23:52 by akahir            #+#    #+#             */
/*   Updated: 2025/01/19 18:43:05 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

// principal functions:
int     main(int argc, char **argv);
void    push_swap(int *stack_a, int *stack_b, int size_a, int size_b);
// functions rules:
void    swap(int *stack, int size,const char *rule);
void    swap_both(int *stack_a, int *stack_b, int size_a, int size_b);
void    push(int *stack_from, int *stack_to, int *size_from, int *size_to, const char *rule);
void    rotate(int *stack, int size, const char *rule);
void    rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);
void    reverse_rotate(int *stack, int size, const char *rule);
void    reverse_rotate_both(int *stack_a, int *stack_b, int size_a, int size_b);
// helper function:
int ft_conditions(int *stack_a, int size_a);
char	**ft_split(const char *s, char c);
int	ft_atoi(const char *str);
#endif