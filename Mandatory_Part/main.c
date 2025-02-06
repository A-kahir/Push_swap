/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:19:19 by akahir            #+#    #+#             */
/*   Updated: 2025/02/06 17:39:43 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_list  *add_node(t_list *stack, int number)
{
    t_list  *new_node;
    t_list *temp;
    int     *content;

    content = malloc(sizeof(int));
    if (!content)
        return (NULL);
    *content = number;
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (free(content), NULL);
    new_node->content = content;
    new_node->index = -1;
    new_node->next = NULL;
    if (!stack)
        return (new_node);
    temp = stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
    return (stack);
}
static t_list *continue_process_arg(char **split, t_list *new_stack)
{
    int i = 0;

    while (split[i])
    {
        new_stack = add_node(new_stack, ft_atoi(split[i]));
        if (!new_stack)
        {
            while (split[i])
                free(split[i++]);
            free(split);
            return (NULL);
        }
        i++;
    }
    return (new_stack);
}


static t_list *process_arg(char *arg, t_list *stack)
{
    char    **split;
    int     i;
    t_list  *new_stack;

    if (spaces_and_tabs(arg) == 0)
    {
        return (NULL);
    }
    split = ft_split(arg, ' ');
    if (!split)
        return (NULL);
    if (!split[0])
        return (free(split), NULL);
    i = 0;
    while (split[i])
    {
        if ((is_valid_number(split[i]) == 0))
        {
            while (split[i])
                free(split[i++]);
            free(split);
            return (NULL);
        }
        i++;
    }
    new_stack = continue_process_arg(split, stack);
    i = 0;
    while (split[i])
        free(split[i++]);
    free(split);

    return (new_stack);
}


static t_list  *parse_arguments(int argc, char **argv)
{
    t_list  *stack_a;
    int     i;
    
    if (argc < 2)
        return (NULL);
    stack_a = NULL;
    i = 1;
    while (i < argc)
    {
        stack_a = process_arg(argv[i], stack_a);
        if (!stack_a)
            return (free_stack(stack_a), NULL);
        i++;
    }
    return (stack_a);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int count;

    if (argc < 2)
        return (1);
    stack_a = parse_arguments(argc, argv);
    if (!stack_a)
        return (write(1, "Error\n", 6), 1);
    if ((ft_double_nb(stack_a) == 1))
		return(write(1, "Error\n", 6), free(stack_a), 1);
    if (ft_already_sorted(stack_a) == 1)
        return(1);
    stack_b = NULL;
    count = 0;
    ft_push_swap(&stack_a, &stack_b, &count);
    while (stack_a)
    {
        printf("stack_a->content %d ==> index[%d]\n", *(stack_a->content), stack_a->index);
        stack_a = stack_a->next;
    }
    printf("count ==> %d", count);
    return (count);
}
