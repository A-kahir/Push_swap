/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:22:32 by akahir            #+#    #+#             */
/*   Updated: 2025/01/09 20:29:06 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*parse_arguments(int argc, char **argv, int *size_a)
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
int main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;

    size_a = 0;
    stack_a = parse_arguments(argc, argv, &size_a);
    if (stack_a == NULL)
        return (write(1, "Error\n", 6), 1);
    stack_b = malloc(size_a * sizeof(int));
    if (stack_b == NULL)
        return (write(1, "Error\n", 6), free(stack_a), 1);
    size_b = size_a;
    push_swap(stack_a, stack_b, size_a, size_b);
    
    int i;
    printf("Stack A:\n");
    for (i = 0; i < size_a; i++)
        printf("stack_a[%d] = %d\n", i, stack_a[i]);
    // printf("Stack B:\n");
    // for (i = 0; i < size_a; i++)
    //     printf("stack_b[%d] = %d\n", i, stack_b[i]);
    free(stack_a);
    free(stack_b);
    return 0;
}
