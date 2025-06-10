/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:12:09 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 19:14:20 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index(int *stack, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	find_index_in_a(int *stack_a, int size_a, int candidate)
{
	int	i;
	int	curr;
	int	next;
	int	min_val;
	int	max_val;

	if (size_a == 0)
		return (0);
	min_val = smallest(stack_a, size_a);
	max_val = largest(stack_a, size_a);
	if (candidate < min_val || candidate > max_val)
		return (find_index(stack_a, size_a, min_val));
	i = 0;
	while (i < size_a)
	{
		curr = stack_a[i];
		next = stack_a[(i + 1) % size_a];
		if (curr < candidate && candidate < next)
			return (i + 1);
		i++;
	}
	return (find_index(stack_a, size_a, min_val));
}

int	find_index_in_b(int *stack_b, int size_b, int value)
{
	int	i;
	int	next;

	if (size_b == 0)
		return (0);
	if (value > largest(stack_b, size_b) || value < smallest(stack_b, size_b))
	{
		i = 0;
		while (i < size_b)
		{
			if (stack_b[i] == largest(stack_b, size_b))
				return ((i + 1) % size_b);
			i++;
		}
	}
	i = 0;
	while (i < size_b)
	{
		next = stack_b[(i + 1) % size_b];
		if (stack_b[i] > value && value > next)
			return ((i + 1) % size_b);
		i++;
	}
	return (0);
}
