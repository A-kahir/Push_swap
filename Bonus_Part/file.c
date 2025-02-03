#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Define the linked list structure
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

// Function to swap the first two elements in a stack
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

// Function to rotate the stack
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

// Function to reverse rotate the stack
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

// Function to push the top element from one stack to another
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

// Function to check if the stack is sorted in ascending order
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

// Function to free the stack memory
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

// Function to initialize the stack with input from argv (correct order)
int init_stack(int argc, char **argv, t_list **stack)
{
    int i;
    int content;

    for (i = argc - 1; i > 0; i--) // Iterate from last argument
    {
        content = atoi(argv[i]);
        add_node(stack, content);
    }
    return 0;
}

// Function to print the stack (for debugging)
void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
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

    // Initialize the stack with input arguments
    if (init_stack(argc, argv, &stack_a) == 1)
        return 1;

    // Print the initial stack for debugging
    printf("Initial stack: ");
    print_stack(stack_a);

    // Continuously read commands until EOF (Ctrl + D)
    while ((read = getline(&line, &len, stdin)) != -1)
    {
        // Remove newline at the end of the command string
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        // Perform the appropriate operation based on the command
        if (strncmp(line, "sa", 2) == 0)
            swap(&stack_a);
        else if (strncmp(line, "ra", 2) == 0)
            rotate(&stack_a);
        else if (strncmp(line, "rra", 3) == 0)
            reverse_rotate(&stack_a);
        else if (strncmp(line, "pa", 2) == 0)
            push(&stack_b, &stack_a);
        else
        {
            write(2, "Error\n", 6);
            free(line);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }

        // Print the stack after each operation for debugging
        printf("Current stack: ");
        print_stack(stack_a);
    }

    // After reading all commands, check if the stack is sorted
    if (is_sorted(stack_a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free(line);
    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}
