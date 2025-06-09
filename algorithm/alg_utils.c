/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:40:42 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 13:01:27 by kwrzosek         ###   ########.fr       */
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
int which_smaller(int a, int b)
{
	if (a < b)
		return (a);
	else if (a > b)
		return (b);
	else 
		return (0);
}
int abs (int a)
{
	if (a < 0)
		return (a* (-1));
	else
		return (a);
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
	return (-1);
}

int find_index_in_a(int *stack_a, int size_a, int push_candidate)
{
    if (size_a == 0)
        return 0;

    int min_val = smallest(stack_a, size_a);
    int max_val = largest(stack_a, size_a);

    if (push_candidate < min_val || push_candidate > max_val)
    {
        return find_index(stack_a, size_a, min_val);
    }
    for (int i = 0; i < size_a; i++)
    {
        int curr = stack_a[i];
        int next = stack_a[(i + 1) % size_a];

        if (curr < push_candidate && push_candidate < next)
        {
            return i + 1;
        }
    }
    return find_index(stack_a, size_a, min_val);
}
int find_index_in_b(int *stack_b, int size_b, int value)
{
	if (size_b == 0)
		return 0;

	int i;
	int max = largest(stack_b, size_b);
	int min = smallest(stack_b, size_b);

	// If value is bigger than max OR smaller than min, it goes after the max
	if (value > max || value < min)
	{
		for (i = 0; i < size_b; i++)
		{
			if (stack_b[i] == max)
				return (i + 1) % size_b;
		}
	}

	// Otherwise, find the position between two elements where it fits
	for (i = 0; i < size_b; i++)
	{
		int curr = stack_b[i];
		int next = stack_b[(i + 1) % size_b];
		if (curr > value && value > next)
			return (i + 1) % size_b;
	}

	// Fallback
	return 0;
}


// int find_index_in_b(int *stack_b, int size_b, int push_candidate)
// {
//     int i;

//     if (size_b == 0)
//         return 0;

//     int min_val = smallest(stack_b, size_b);
//     int max_val = largest(stack_b, size_b);

//     if (push_candidate > max_val || push_candidate < min_val)
// {
//     for (i = 0; i < size_b; i++)
//     {
//         if (stack_b[i] == max_val)
//             return (i + 1) % size_b;
//     }
// }

//     for (i = 0; i < size_b - 1; i++)
//     {
//         if (push_candidate < stack_b[i] && push_candidate > stack_b[i + 1])
//             return i + 1;
//     }
//     if (push_candidate < stack_b[size_b - 1] && push_candidate > stack_b[0])
//         return 0;

//     return 0;
// }
