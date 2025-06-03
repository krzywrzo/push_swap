/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:59 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/03 19:26:28 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(s_args *stacks)
{
	int	i;

	i = 0;
	printf("STACK A: \n");
	printf("size: %i\n", stacks->size_a);
	while (i < stacks->size_a)
	{
		printf("%i\n", stacks->stack_a[i]);
		i++;
	}
	i = 0;
	printf("STACK B: \n");
	printf("size: %i\n", stacks->size_b);
	while (i < stacks->size_b)
	{
		printf("%i\n", stacks->stack_b[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	s_args	*stacks;
	char	**temp_stack;

	stacks = malloc(sizeof(s_args));
	if (!stacks)
	{
		free_stack(stacks);
		return (print_error());
	}
	stacks->size_a = argc - 1;
	// temp_stack = malloc(sizeof(char *) * stacks->size_a);
	// if (!temp_stack)
	// {
	//     // free_split(temp_stack);
	// 	free_stack(stacks);
	// 	return (0);
	// }
	if (argc == 1)
	{
		free_stack(stacks);
		return (print_error());
	}
	else if (argc == 2)
	{
		temp_stack = ft_split(argv[1], ' ');
		if (!temp_stack)
		{
            free_split(temp_stack);
			free_stack(stacks);
			return (print_error());
		}
		stacks->size_a = stack_size(temp_stack);
		// printf("size: %i", stacks->size_a);
	}
	else
		temp_stack = copy_args(argc, argv);
	stacks->stack_a = temp_to_stack(temp_stack, stacks->size_a);
	if (!stacks->stack_a)
	{
		free_split(temp_stack);
		free_stack(stacks);
		return (print_error());
	}
	free_split(temp_stack);
	if (is_valid(stacks->stack_a, stacks->size_a) == 1)
	{
		free_stack(stacks);
		return (print_error());
	}
	if (stacks->size_a <= 3)
        sort_three(stacks);
    else
        push_swap(stacks);

	free_stack(stacks);
	return (0);
}
