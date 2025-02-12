


#include "ft_push_swap_bonus.h"

int execute_instruction(char *instruction, t_list **stack_a, t_list **stack_b, int *count)
{
    if (!ft_strcmp(instruction, "sa\n"))
        swap(stack_a, count);
    else if (!ft_strcmp(instruction, "sb\n"))
        swap(stack_b, count);
    else if (!ft_strcmp(instruction, "ss\n"))
        swap_both(stack_a, stack_b, count);
    else if (!ft_strcmp(instruction, "pa\n"))
        push(stack_b, stack_a, count);
    else if (!ft_strcmp(instruction, "pb\n"))
        push(stack_a, stack_b, count);
    else if (!ft_strcmp(instruction, "ra\n"))
        rotate(stack_a, count);
    else if (!ft_strcmp(instruction, "rb\n"))
        rotate(stack_b, count);
    else if (!ft_strcmp(instruction, "rr\n"))
        rotate_both(stack_a, stack_b, count);
    else if (!ft_strcmp(instruction, "rra\n"))
        reverse_rotate(stack_a, count);
    else if (!ft_strcmp(instruction, "rrb\n"))
        reverse_rotate(stack_b, count);
    else if (!ft_strcmp(instruction, "rrr\n"))
        reverse_rotate_both(stack_a, stack_b, count);
    else
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    char *instruction;
    int count = 0;
    int i;
    t_list *new_node;

    if (argc < 2)
        return 1;
    i = 1;
    while (i < argc)
    {
        new_node = create_node(ft_atoi(argv[i]));
        if (!new_node)
            return (free_stack(stack_a), 1);
        if (!stack_a)
            stack_a = new_node;
        else
        {
            t_list *last = stack_a;
            while (last->next)
                last = last->next;
            last->next = new_node;
        }
        i++;
    }
    while ((instruction = get_next_line(0)))
    {
        if (!execute_instruction(instruction, &stack_a, &stack_b, &count))
            return (write(2, "Error\n", 6), free(instruction), free_stack(stack_a), free_stack(stack_b), 1);
        free(instruction);
    }
    if (is_sorted(stack_a) && !stack_b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(stack_a);
    free_stack(stack_b);
}
