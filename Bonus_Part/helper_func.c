


#include "ft_push_swap_bonus.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void free_stack(t_list *stack)
{
    t_list *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp->content);
        free(temp);
    }
}

t_list *create_node(int content)
{
    t_list *new;
    int *content_ptr;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    content_ptr = malloc(sizeof(int));
    if (!content_ptr)
        return (free(new), NULL);
    *content_ptr = content;
    new->content = content_ptr;
    new->next = NULL;
    return (new);
}
