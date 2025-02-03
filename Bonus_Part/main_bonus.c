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

void ft_strcmplist(char *str, t_list a, t_list **b)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_compare(str[i], a, b);
        i++;
    }
}

void ft_check_str(char new_str, charrst, t_list **a)
{
    if (!rst)
        free_leak(new_str, rst, a);
}

void help_me(char rst, t_list **a)
{
    t_list *current;
    int i;

    i = 0;
    current = NULL;
    if (!rst)
    {
        while (a)
        {
            current = (a)->next;
            if ((a)->index != i)
            {
                write(1, "KO\n", 3);
                ft_lstclear(a);
                exit(1);
            }
            free(*a);
            *a = current;
            i++;
        }
        write(1, "OK\n", 3);
        return;
    }
}

static void free_leak(char str, char new_str, t_list *a)
{
    write(1, "Error\n", 6);
    get_next_line(-1);
    ft_lstclear(a);
    if (new_str)
        free(new_str);
    free(str);
    exit(1);
}

int read_line(t_list a, t_list b)
{
    char rst;
    char temp;
    char new_str;
    char **str;

    new_str = NULL;
    rst = get_next_line(0);
    if (!rst)
        help_me(rst, a);
    while (rst)
    {
        ft_check_str(new_str, rst, a);
        temp = ft_strjoin(new_str, rst);
        free(new_str);
        new_str = temp;
        free(rst);
        rst = get_next_line(0);
    }
    str = ft_split(new_str, '\n');
    if (!str)
        return (ft_lstclear(a), 1);
    ft_strcmplist(str, a, b);
    free(new_str);
    return (ft_freestr(str), 0);
}
int main(int argc, char **argv)
{
    t_list *stack_a;;
    t_list *stack_b;
    int len;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (init_stack(argc, argv, &stack_a) == 1)
        return (1);
    len = ft_size_liste(stack_a);
    if (check_duplicate(stack_a) == 0)
    {
        ft_lstclear(stack_a);
        write(2, "Error\n", 6);
        return (1);
    }
    ft_index_by_content(stack_a);
    if (read_line(&stack_a, &stack_b) == 1)
        return (1);
    check_sort(stack_a, &len);
    if (stack_b)
        ft_lstclear(stack_b);
    return (0);
}