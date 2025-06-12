/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:16:54 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 18:35:01 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	calc_min_cost(t_args *stacks, t_cost *cost)
{
	int	*cost_arr;
	int	i;
	int	min_cost;
	int	min_value;

	i = 0;
	cost_arr = malloc(sizeof(int) * stacks->size_a);
	while (i < stacks->size_a)
	{
		cost_arr[i] = calc_cost_optimized(stacks, cost, i);
		i++;
	}
	min_value = cost_arr[0];
	i = 1;
	while (i < stacks->size_a)
	{
		if (cost_arr[i] < min_value)
		{
			min_value = cost_arr[i];
			min_cost = i;
		}
		i++;
	}
	free(cost_arr);
	return (i);
}

void	push_a(t_args *stacks)
{
	int	top_of_b;
	int	place_in_a;
	int	count;

	while (stacks->size_b != 0)
	{
		top_of_b = stacks->stack_b[0];
		place_in_a = find_index_in_a(stacks->stack_a, stacks->size_a, top_of_b);
		if (place_in_a <= stacks->size_a / 2)
		{
			count = place_in_a;
			while (count-- > 0)
				ra(stacks, 1);
		}
		else
		{
			count = stacks->size_a - place_in_a;
			while (count-- > 0)
				rra(stacks, 1);
		}
		pa(stacks, 1);
	}
}
