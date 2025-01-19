/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   	main.c                			                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:22:32 by akahir            #+#    #+#             */
/*   Updated: 2025/01/07 18:22:33 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
    Integer Overflow/Underflow: Reject numbers outside the range of a 32-bit signed integer (INT_MIN to INT_MAX).

    Duplicate Numbers: Reject input containing duplicate integers.

    Non-Numeric Input: Reject input containing characters, words, or symbols that cannot be converted to valid integers.

    Empty Input or No Arguments: Reject if no arguments or only whitespace are provided.

    Invalid Format: Reject inputs with invalid formatting, such as multiple spaces, empty strings, or numbers mixed with characters (e.g., 12a).

    Leading/Trailing Spaces: Handle inputs with leading or trailing spaces correctly.

    Edge Cases: Reject negative zeros (-0), as they can be interpreted as duplicates of 0.
*/

static	int	*parse_arguments(int argc, char **argv, int *size_a)
{
	int *stack_a;
	int i;

	if (argc < 2)
		return (NULL);
	stack_a = NULL;
	i = 0;
	while (i < *size_a)
	{
		stack_a[i] = ft_split(argv[i], ' ');
		i++;
	}
	stack_a = malloc((argc - 1) * sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	*size_a = argc - 1;
	i = 0;
	while (i < *size_a)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack_a);
}
int	main(int argc, char **argv)
{
	int size_a;
	int size_b;
	int cantinue;
	int *stack_a;
	int *stack_b;

    size_a = 0;
    stack_a = parse_arguments(argc, argv, &size_a);
    if (stack_a == NULL)
        return (write(1, "Error\n", 6), 1);
	cantinue = ft_conditions(stack_a, size_a);
	if (cantinue == 1)
		return (write(1, "Error\n", 6), free(stack_a), 1);
	size_b = 0;
    stack_b = malloc(size_a * sizeof(int));
    if (stack_b == NULL)
        return (write(1, "Error\n", 6), free(stack_a), 1);
	push_swap(stack_a, stack_b, size_a, size_b);
	
	printf("\nBefore operation (size_a: %d, size_b: %d)\n", size_a, size_a);
    printf("Stack A:\n");
    int j = 0;
    while (j < size_a)
    {
        printf("stack_A[%d]=> %d\n", j, stack_a[j]);
        j++;
    }
	printf("\nStack B:\n");
	j = 0;
	while (j < size_a)
	{
		printf("stack_B[%d]=> %d\n", j, stack_b[j]);
		j++;
	}
    free(stack_a);
    free(stack_b);
}
