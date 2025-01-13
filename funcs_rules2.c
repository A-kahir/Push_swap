/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_rules2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:23:20 by akahir            #+#    #+#             */
/*   Updated: 2025/01/07 18:23:21 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void    push(int *stack_from, int *stack_to, int *size_from, int *size_to, const char *rule)
{
    int i;
    
    if (*size_from > 0)
    {
        i = *size_to;
        while (i > 0)
        {
            stack_to[i] = stack_to[i - 1];
            i--;
        }
        stack_to[0] = stack_from[0];
        i = 0;
        while (i < *size_from - 1)
        {
            stack_from[i] = stack_from[i + 1];
            i++;
        }
        (*size_to)++;
        (*size_from)--;
    }
	if (rule = "pa")
		write(1, "pa\n", 3);
	else if (rule = "pb")
		write(1, "pb\n", 3);
}

int main()
{
    int stack_from[] = {3, 2, 1, 5, 4};
    int size = 5;
    int *stack_to = malloc(*size * sizeof(int));
    push(stack_from, stack_to, size, size, "pa");

    int k;
    int l;
    printf("Stack A:\n");
    for (k = 0; k < *size; k++)
        printf("stack_a[%d] = %d\n", k, stack_from[k]);
    
    printf("Stack B:\n");
    for (l = 0; l < *size; l++)
        printf("stack_b[%d] = %d\n", l, stack_to[l]);
}