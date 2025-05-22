/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:40:42 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/22 15:52:02 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int largest(int *stack, int size)
{
    int i;
    int max;

    i = 0;
    max = stack[0];
    while (i < size)
    {
        if (max < stack[i])
            max = stack[i];
        i++;
    }
    return (max);
}

int smallest(int *stack, int size)
{
    int i;
    int min;

    i = 1;
    min = stack[0];
    while (i < size)
    {
        if (min > stack[i])
            min = stack[i];
        i++;
    }
    return (min);
}

int find_index (int *stack, int size, int num)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (i);
}

int		find_index_in_a (int *stack_a, int size_a, int push_candidate)
{
	int i;

	i = 1;
	// if (push_candidate > stack_a[i] && push_candidate < stack_a[size_a - 1])
	// 	i = 0;
	// else if (push_candidate > largest(stack_a, size_a) || push_candidate < smallest(stack_a, size_a))
	// 	i = find_index(stack_a, size_a, push_candidate);
	// else 
	// {
	// 	while (push_candidate > stack_a[i] && push_candidate < stack_a[i + 1])
	// 		i++;
	// }

	if (push_candidate < stack_a[i] && push_candidate > stack_a[size_a - 1])
		// i = find_index(stack_a, size_a, push_candidate);
		i = 0;
	else if (push_candidate > largest(stack_a, size_a) || push_candidate < smallest(stack_a, size_a))
		i = find_index(stack_a, size_a, smallest(stack_a, size_a));
	else 
	{
		while (push_candidate < stack_a[i] || push_candidate > stack_a[i + 1])
			i++;
	}
	return (i);
}

// int		find_index_in_b (int *stack_b, int size_b, int push_candidate)
// {
// 	int i;
// 	int	largest_b;
// 	int	smallest_b;

// 	i = 0;
// 	if (push_candidate > stack_b[0])
// 		return (0);
// 	else if (push_candidate < stack_b[size_b - 1])
// 		return (size_b - 1);
// 	else
// 	{
// 		while ((push_candidate < stack_b[i] && push_candidate > stack_b[i + 1]))
// 			i++;
// 	}
// 	return (i);
// }

int		find_index_in_b (int *stack_b, int size_b, int push_candidate)
{
	int i;
	int	largest_b;
	int	smallest_b;

	 i = 1;
	//  printf("i from index_b: %i\n", i);
	if (push_candidate > stack_b[i] && push_candidate < stack_b[size_b - 1])
		i = 0;
	else if (push_candidate > largest(stack_b, size_b) || push_candidate < smallest(stack_b, size_b))
		i = find_index(stack_b, size_b, largest(stack_b, size_b));
	else 
	{
		while (push_candidate > stack_b[i] && push_candidate < stack_b[i + 1])
			i++;		
	}
	return (i);
}