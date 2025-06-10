/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:10:15 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/10 17:05:43 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_args	*stacks;
	t_cost	*cost;
	char	**temp_stack;

	stacks = malloc(sizeof(t_args));
	cost = malloc(sizeof(t_cost));
	if (!stacks || argc == 1)
		print_error(NULL, stacks, cost, 1);
	else if (argc == 2)
		temp_stack = ft_split(argv[1], ' ');
	else
		temp_stack = copy_args(argc, argv);
	if (is_valid_input(temp_stack) == 1)
		print_error(temp_stack, stacks, cost, 1);
	stacks->size_a = stack_size(temp_stack);
	stacks->stack_a = temp_to_stack(temp_stack, stacks->size_a);
	if (is_valid_stack(stacks->stack_a, stacks->size_a) == 1)
		print_error(temp_stack, stacks, cost, 1);
	free_split(temp_stack);
	if (stacks->size_a <= 3)
		sort_three(stacks);
	else
		push_swap(stacks, cost);
	free_stack(stacks, cost);
	return (0);
}

void	print_stacks(t_args *stacks)
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
