/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:10:15 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/05 18:49:05 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	s_args	*stacks;
	char	**temp_stack;

	stacks = malloc(sizeof(s_args));
	if (!stacks || argc == 1)
		print_error(NULL, stacks, 1);
	else if (argc == 2)
		temp_stack = ft_split(argv[1], ' ');
	else
		temp_stack = copy_args(argc, argv);
	if (is_valid_input(temp_stack) == 1)
		print_error(temp_stack, stacks, 1);
	stacks->size_a = stack_size(temp_stack);
	stacks->stack_a = temp_to_stack(temp_stack, stacks->size_a);
	if (is_valid_stack(stacks->stack_a, stacks->size_a) == 1)
		print_error(temp_stack, stacks, 1);
	free_split(temp_stack);
	if (stacks->size_a <= 3)
		sort_three(stacks);
	else
		push_swap(stacks);
	// print_stacks(stacks);
	free_stack(stacks);
	return (0);
}
