#include "push_swap.h"

int main(int argc, char **argv)
{
    int *stack_a;
    int stack_size;
    char **temp_stack; 

    stack_size = argc - 1;
    temp_stack = malloc(sizeof(char *) * stack_size);
    if (argc == 1)
    {
        printf("to few arguments");
        return (0);
    }
    else if (argc == 2)
    {
        temp_stack = ft_split(argv[1], ' ');
        stack_size = ft_strlen(*temp_stack);
    }
    else
		temp_stack = copy_args(argc, argv);
	stack_a = temp_to_stack(temp_stack, stack_size);
	free(temp_stack);
}