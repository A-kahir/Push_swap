#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_list {
    int content;
    int index;
    struct s_list *next;
} t_list;

// Function to create a new node
t_list *new_node(int content)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->index = -1;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the stack
void add_node(t_list **stack, int content)
{
    t_list *node = new_node(content);
    node->next = *stack;
    *stack = node;
}

// Swap the first two elements of the stack
void swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!*stack || !(*stack)->next)
        return;
    
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

// Swap the first two elements of both stacks
void swap_both(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

// Rotate the stack (move top element to bottom)
void rotate(t_list **stack)
{
    t_list *first;
    t_list *last;

    if (!*stack || !(*stack)->next)
        return;
    
    first = *stack;
    *stack = (*stack)->next;
    last = *stack;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
}

// Rotate both stacks
void rotate_both(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

// Reverse rotate the stack (move bottom element to top)
void reverse_rotate(t_list **stack)
{
    t_list *second_last;
    t_list *last;

    if (!*stack || !(*stack)->next)
        return;
    
    second_last = *stack;
    while (second_last->next->next)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

// Reverse rotate both stacks
void reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}

// Push the top element from one stack to another
void push(t_list **from, t_list **to)
{
    t_list *tmp;

    if (!*from)
        return;
    
    tmp = *from;
    *from = (*from)->next;
    tmp->next = *to;
    *to = tmp;
}

// Check if the stack is sorted in ascending order
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

// Free the stack memory
void free_stack(t_list *stack)
{
    t_list *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

// Initialize the stack with input from argv
int init_stack(int argc, char **argv, t_list **stack)
{
    int i;
    int content;

    for (i = argc - 1; i > 0; i--)
    {
        content = atoi(argv[i]);
        add_node(stack, content);
    }
    return 0;
}

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc == 1)
        return 0;
    
    if (init_stack(argc, argv, &stack_a) == 1)
        return 1;

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (strncmp(line, "sa", 2) == 0)
            swap(&stack_a);
        else if (strncmp(line, "sb", 2) == 0)
            swap(&stack_b);
        else if (strncmp(line, "ss", 2) == 0)
            swap_both(&stack_a, &stack_b);
        else if (strncmp(line, "ra", 2) == 0)
            rotate(&stack_a);
        else if (strncmp(line, "rb", 2) == 0)
            rotate(&stack_b);
        else if (strncmp(line, "rr", 2) == 0)
            rotate_both(&stack_a, &stack_b);
        else if (strncmp(line, "rra", 3) == 0)
            reverse_rotate(&stack_a);
        else if (strncmp(line, "rrb", 3) == 0)
            reverse_rotate(&stack_b);
        else if (strncmp(line, "rrr", 3) == 0)
            reverse_rotate_both(&stack_a, &stack_b);
        else if (strncmp(line, "pa", 2) == 0)
            push(&stack_b, &stack_a);
        else if (strncmp(line, "pb", 2) == 0)
            push(&stack_a, &stack_b);
        else
        {
            write(2, "Error\n", 6);
            free(line);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
    }

    if (is_sorted(stack_a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free(line);
    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}
