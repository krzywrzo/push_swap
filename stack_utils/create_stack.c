#include "push_swap.h"

char	**copy_args(int argc, char **argv)
{
	int		i;
	char	**temp_stack;

	temp_stack = malloc(sizeof(char *) * argc);
	if (!temp_stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp_stack[i - 1] = ft_strdup(argv[i]);
		if (!temp_stack[i - 1])
			return (NULL);
		i++;
	}
	temp_stack[argc - 1] = NULL;
	return (temp_stack);
}

int	*temp_to_stack(char **temp_stack, int stack_size)
{
	int	*stack;
	int	i;

	// stack = calloc(stack_size, sizeof(int));
	stack = malloc(sizeof(int) * stack_size);
	if (!stack)
	{
		free(stack);
		return (0);
	}
	i = 0;
	while (temp_stack[i])
	{
		stack[i] = ft_atoi(temp_stack[i]);
		i++;
	}
	// free(stack);
	return (stack);
}
