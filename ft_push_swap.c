/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:22:32 by akahir            #+#    #+#             */
/*   Updated: 2025/01/07 18:22:33 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*parse_arguments(int argc, char **argv, int *size_a)
{
	int *stack_a;
	int i;

	if (argc < 2)
		return (NULL);
	stack_a = malloc((argc - 1) * sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	*size_a = argc - 1;
	while (i < *size_a)
	{
		stack_a[i] = atoi(argv[i + 1]);
		i++;
	}
	return (stack_a);
}
int	main(int argc, char **argv)
{
	int size_a;
	int *stack_a;
	int *stack_b;
	int square_nb;
	int i;

    size_a = 0;
    stack_a = parse_arguments(argc, argv, &size_a);
    if (stack_a == NULL)
        return (write(1, "Error\n", 7), 1);
    stack_b = malloc(size_a * sizeof(int));
    if (stack_b == NULL)
        return (write(1, "Error\n", 7), free(stack_a), 1);
	square_nb = size_a / 2;
	printf("sqaure => %d\n", square_nb);
	i = 0;
	while (i < square_nb)
	{
		stack_b[i] = stack_a[i + square_nb];
		i++;
	}
	printf("stack_a[i + 1] => %d\n", stack_b[i]);
	if (stack_b[])
	{
		printf("here");
	}
    //push_swap(stack_a, stack_b, size_a);

	// int j;
	// printf("Stack A:\n");
    // for (i = 0; i < square_nb; i++)
    //     printf("stack_a[%d] = %d\n", i, stack_a[i]);
    
    // printf("Stack B:\n");
    // for (j = 0; j < square_nb; j++)
    //     printf("stack_b[%d] = %d\n", j, stack_b[j]);
	
    free(stack_a);
    free(stack_b);
}
