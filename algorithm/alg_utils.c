/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:40:42 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/03 15:04:28 by kwrzosek         ###   ########.fr       */
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

void mixed_rrotate(s_args *stacks, int a_index, int b_index)
{
	int i;
	int rra_counter;

	i = 0;
	rra_counter = stacks->size_a - a_index - 1;
	while (i < rra_counter)
	{
		rra(stacks, 1);
		i++;
	}
	i = 0;
	while (i < b_index)
	{
		rb(stacks, 1);
		i++;
	}
}

void mixed_rotate(s_args *stacks, int a_index, int b_index)
{
	int i;
	int rrb_counter;

	i = 0;
	rrb_counter = stacks->size_b - b_index - 1;
	while (i < rrb_counter)
	{
		rrb(stacks, 1);
		i++;
	}
	i = 0;
	while (i < a_index)
	{
		ra(stacks, 1);
		i++;
	}
}

void reverse_rotate(s_args *stacks, int a_index, int b_index)
{
	int rra_rrb;
	int rrr_counter;

	rrr_counter = which_smaller(a_index, b_index);
	rra_rrb = a_index - b_index;
	while (rrr_counter > 0)
	{
		rrr(stacks, 1);
		rrr_counter--;
	}
	if (rrr_counter > 0)
		while (rrr_counter > 0)
		{
			rra(stacks, 1);
			rrr_counter--;
		}
	else if (rrr_counter < 0)
		while (rrr_counter < 0)
		{
			rrb(stacks, 1);
			rrr_counter++;
		}
}
void rotate(s_args *stacks, int a_index, int b_index)
{
	int ra_rb;
	int rr_counter;

	if (a_index == 0 || b_index == 0)
		rr_counter = 0;
	else 
		rr_counter = which_smaller(a_index, b_index);
	printf("rr_counter: %i\n", rr_counter);
	ra_rb = a_index - b_index;
	while (rr_counter > 0)
	{
		printf("first while in rotate\n");
		rr(stacks, 1);
		rr_counter--;
	}
	if (rr_counter > 0)
		while (rr_counter > 0)
		{
			printf("second while in rotate\n");
			ra(stacks, 1);
			rr_counter--;
		}
	else if (rr_counter < 0)
		while (rr_counter < 0)
		{
			printf("third while in rotate\n");
			rb(stacks, 1);
			rr_counter++;
		}
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
    {
        return 0;
    }

    int min_val = smallest(stack_a, size_a);
    int max_val = largest(stack_a, size_a);

    if (push_candidate < min_val || push_candidate > max_val)
    {
        int min_idx = find_index(stack_a, size_a, min_val);
		return min_idx;
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

    return 0;
}

int find_index_in_b(int *stack_b, int size_b, int push_candidate)
{
	int i;

	if (size_b == 0)
		return 0;
	if (push_candidate > largest(stack_b, size_b) ||
		push_candidate < smallest(stack_b, size_b))
	{
		int max_val = largest(stack_b, size_b);
		for (i = 0; i < size_b; i++)
		{
			if (stack_b[i] == max_val)
				return (i + 1) % size_b;
		}
	}
	for (i = 0; i < size_b - 1; i++)
	{
		if (push_candidate < stack_b[i] && push_candidate > stack_b[i + 1])
			return i + 1;
	}
	return 0;
}
