/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:38:52 by akahir            #+#    #+#             */
/*   Updated: 2025/02/03 21:41:42 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

t_list *new_node(int content)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = &content;
    node->index = -1;
    node->next = NULL;
    return node;
}

void add_node(t_list **stack, int content)
{
    t_list *node = new_node(content);
    node->next = *stack;
    *stack = node;
}

int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (stack->content > stack->next->content)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void process_commands(t_list **stack_a, t_list **stack_b, int *count)
{
    char *line;

    line = NULL;
    while ((line = get_next_line(0)) != NULL)
    {
        if (line[0] == '\n')
        {
            free(line);
            continue;
        }
        if (ft_strcmp(line, "sa\n") == 0)
            swap(stack_a, count);
        else if (ft_strcmp(line, "sb\n") == 0)
            swap(stack_b, count);
        else if (ft_strcmp(line, "pa\n") == 0)
            push(stack_a, stack_b, count);
        else if (ft_strcmp(line, "pb\n") == 0)
            push(stack_a, stack_b, count);
        else if (ft_strcmp(line, "ra\n") == 0)
            rotate(stack_a, count);
        else if (ft_strcmp(line, "rb\n") == 0)
            rotate(stack_b, count);
        else if (ft_strcmp(line, "rra\n") == 0)
            reverse_rotate(stack_a, count);
        else if (ft_strcmp(line, "rrb\n") == 0)
            reverse_rotate(stack_b, count);
        else
        {
            write(1, "Error\n", 6);
            free(line);
            exit(1);
        }
        free(line);
    }
}

int main(int argc, char **argv)
{
    char **split;
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int i;
    int count = 0;

    if (argc < 2)
        return (1);
    i = 0;
    while (argv[i] != NULL)
    {
        split = ft_split(argv[i], ' ');
        i++;
    }
    i = 0;
    while (split[i])
    {
        if ((is_valid_number(split[i]) == 0))
        {
            while (split[i])
                free(split[i++]);
            return (write(1, "Error\n", 6), free(split), 1);
        }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        add_node(&stack_a, ft_atoi(argv[i]));
        i++;
    }
    process_commands(&stack_a, &stack_b, &count);
    if (is_sorted(stack_a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free(stack_a);
    free(stack_b);
    return (0);
}
