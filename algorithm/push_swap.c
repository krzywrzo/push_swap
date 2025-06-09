/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 13:31:58 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(s_args *stacks, int i)
{
	int	push_candidate;
	int	a_index;
	int	b_index;
	int	cost;

	push_candidate = stacks->stack_a[i];
	a_index = i;
	b_index = find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
	cost = 0;
	if (a_index > stacks->size_a / 2)
		cost += stacks->size_a - a_index;
	else
		cost += a_index;
	if (b_index > stacks->size_b / 2)
		cost += stacks->size_b - b_index;
	else
		cost += b_index;
	return (cost + 1);
}

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	min(int a, int b)
{
	return ((a < b) ? a : b);
}

int	calc_cost_optimized(s_args *stacks, int a_index)
{
	int	push_candidate;
	int	b_index;
	int	size_a;
	int	size_b;
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	min_cost;

	push_candidate = stacks->stack_a[a_index];
	b_index = find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
	size_a = stacks->size_a;
	size_b = stacks->size_b;
	
	int rev_a = (a_index == 0) ? 0 : size_a - a_index;
	int rev_b = (b_index == 0) ? 0 : size_b - b_index;
	
	cost_rr = max(a_index, b_index);
	cost_rrr = max(rev_a, rev_b);
	cost_ra_rrb = a_index + rev_b;
	cost_rra_rb = rev_a + b_index;
	
	min_cost = cost_rr;
	min_cost = min(min_cost, cost_rrr);
	min_cost = min(min_cost, cost_ra_rrb);
	min_cost = min(min_cost, cost_rra_rb);
	return (min_cost + 1);
}
void	do_move(s_args *stacks, int a_index)
{
	int	b_index;
	int	size_a;
	int	size_b;
	int	ra_count;
	int	rb_count;
	int	rra_count;
	int	rrb_count;
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	min_cost;
	int	strategy;

// 	printf(">>> DO_MOVE start: A_size=%d, B_size=%d, a_index=%d, a_top=%d\n",
// 		stacks->size_a, stacks->size_b, a_index, stacks->stack_a[a_index]);
//  printf("Stack A: ");
//  for (int i = 0; i < stacks->size_a; i++)
// 	 printf("%d ", stacks->stack_a[i]);
//  printf("\nStack B: ");
//  for (int i = 0; i < stacks->size_b; i++)
// 	 printf("%d ", stacks->stack_b[i]);
//  printf("\n");
 

	if (b_index == stacks->size_b)
	b_index = 0;

	b_index = find_index_in_b(stacks->stack_b, stacks->size_b,
			stacks->stack_a[a_index]);
// printf("→ target b_index for %d is %d\n", stacks->stack_a[a_index], b_index);

	size_a = stacks->size_a;
	size_b = stacks->size_b;
	ra_count = a_index;
rb_count = b_index;
rra_count = (a_index == 0) ? 0 : size_a - a_index;
rrb_count = (b_index == 0) ? 0 : size_b - b_index;

	cost_rr = max(ra_count, rb_count);
	cost_rrr = max(rra_count, rrb_count);
	cost_ra_rrb = ra_count + rrb_count;
	cost_rra_rb = rra_count + rb_count;
	min_cost = cost_rr;
	strategy = 0;
	if (cost_rrr < min_cost)
	{
		min_cost = cost_rrr;
		strategy = 1;
	}
	if (cost_ra_rrb < min_cost)
	{
		min_cost = cost_ra_rrb;
		strategy = 2;
	}
	if (cost_rra_rb < min_cost)
	{
		min_cost = cost_rra_rb;
		strategy = 3;
	}

	// Perform rotations based on strategy
	if (strategy == 0)  // rr
	{
		while (ra_count > 0 && rb_count > 0)
		{
			rr(stacks, 1);
			ra_count--;
			rb_count--;
		}
		while (ra_count-- > 0)
			ra(stacks, 1);
		while (rb_count-- > 0)
			rb(stacks, 1);
	}
	else if (strategy == 1)  // rrr
	{
		while (rra_count > 0 && rrb_count > 0)
		{
			rrr(stacks, 1);
			rra_count--;
			rrb_count--;
		}
		while (rra_count-- > 0)
			rra(stacks, 1);
		while (rrb_count-- > 0)
			rrb(stacks, 1);
	}
	else if (strategy == 2)  // ra + rrb
	{
		while (ra_count-- > 0)
			ra(stacks, 1);
		while (rrb_count-- > 0)
			rrb(stacks, 1);
	}
	else if (strategy == 3)  // rra + rb
	{
		while (rra_count-- > 0)
			rra(stacks, 1);
		while (rb_count-- > 0)
			rb(stacks, 1);
	}

	// Now push top of A to B
	pb(stacks, 1);
}

// void	do_move(s_args *stacks, int a_index)
// {
// 	int	b_index;
// 	int	size_a;
// 	int	size_b;
// 	int	ra_count;
// 	int	rb_count;
// 	int	rra_count;
// 	int	rrb_count;
// 	int	cost_rr;
// 	int	cost_rrr;
// 	int	cost_ra_rrb;
// 	int	cost_rra_rb;
// 	int	min_cost;
// 	int	strategy;

// 	b_index = find_index_in_b(stacks->stack_b, stacks->size_b,
// 			stacks->stack_a[a_index]);
// 	size_a = stacks->size_a;
// 	size_b = stacks->size_b;
// 	ra_count = a_index;
// 	rb_count = b_index;
// 	rra_count = size_a - a_index;
// 	rrb_count = size_b - b_index;
// 	cost_rr = (ra_count > rb_count) ? ra_count : rb_count;
// 	cost_rrr = (rra_count > rrb_count) ? rra_count : rrb_count;
// 	cost_ra_rrb = ra_count + rrb_count;
// 	cost_rra_rb = rra_count + rb_count;
// 	min_cost = cost_rr;
// 	strategy = 0;
// 	if (cost_rrr < min_cost)
// 	{
// 		min_cost = cost_rrr;
// 		strategy = 1;
// 	}
// 	if (cost_ra_rrb < min_cost)
// 	{
// 		min_cost = cost_ra_rrb;
// 		strategy = 2;
// 	}
// 	if (cost_rra_rb < min_cost)
// 	{
// 		min_cost = cost_rra_rb;
// 		strategy = 3;
// 	}
// 	pb(stacks, 1);
// }

void	sort_three(s_args *stacks)
{
	int	*a;

	a = stacks->stack_a;
	if (stacks->size_a != 3)
		return ;
	if (a[0] < a[1] && a[1] < a[2])
		return ;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(stacks, 1);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(stacks, 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		rra(stacks, 1);
}

void	print_stack(const char *name, int *stack, int size)
{
	printf("%s (size %d): ", name, size);
	for (int i = 0; i < size; i++)
		printf("%d ", stack[i]);
	printf("\n");
}
int is_sorted(int *stack, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (stack[i] > stack[i + 1])
			return 0;
	}
	return 1;
}
void push_swap(s_args *stacks)
{
	int	*cost_arr;
	int	i;
	int	min_cost;
	int	min_value;
	int	max_val;
	int	max_idx;

	stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
	stacks->size_b = 0;
	pb(stacks, 1);
	pb(stacks, 1);
	while (stacks->size_a > 3)
	{
		cost_arr = malloc(sizeof(int) * stacks->size_a);
		for (i = 0; i < stacks->size_a; i++)
			cost_arr[i] = calc_cost_optimized(stacks, i);
		
		min_value = cost_arr[0];
		min_cost = 0;
		for (i = 1; i < stacks->size_a; i++)
		{
			if (cost_arr[i] < min_value)
			{
				min_value = cost_arr[i];
				min_cost = i;
			}
		}
		free(cost_arr);
		
		do_move(stacks, min_cost);
	}
	sort_three(stacks);
	while (stacks->size_b > 0)
	{
		max_val = largest(stacks->stack_b, stacks->size_b);
		max_idx = find_index(stacks->stack_b, stacks->size_b, max_val);
		
		if (max_idx <= stacks->size_b / 2)
			while (max_idx-- > 0)
				rb(stacks, 1);
		else
			for (int i = 0; i < stacks->size_b - max_idx; i++)
				rrb(stacks, 1);
		
		pa(stacks, 1);

		if (stacks->size_a > 1 && stacks->stack_a[0] > stacks->stack_a[1])
			sa(stacks, 1);
	}
	
	int min_idx = find_index(stacks->stack_a, stacks->size_a,
		smallest(stacks->stack_a, stacks->size_a));
		if (min_idx <= stacks->size_a / 2)
		{
			while (min_idx-- > 0)
				ra(stacks, 1);
		}
		else
		{
			for (int i = 0; i < stacks->size_a - min_idx; i++)
				rra(stacks, 1);
		}
		

}




// void	push_swap(s_args *stacks)
// {
// 	int	*cost_arr;
// 	int	i;
// 	int	min_cost_idx;

// 	stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
// 	stacks->size_b = 0;

// 	// Initial push to B
// 	pb(stacks, 1);
// 	pb(stacks, 1);

// 	// Push rest with optimized cost strategy
// 	while (stacks->size_a > 3)
// 	{
// 		cost_arr = malloc(sizeof(int) * stacks->size_a);
// 		for (i = 0; i < stacks->size_a; i++)
// 			cost_arr[i] = calc_cost_optimized(stacks, i);
// 		min_cost_idx = 0;
// 		for (i = 1; i < stacks->size_a; i++)
// 		{
// 			if (cost_arr[i] < cost_arr[min_cost_idx])
// 				min_cost_idx = i;
// 		}
// 		free(cost_arr);
// 		do_move(stacks, min_cost_idx);
// 	}

// 	// Sort remaining 3
// 	sort_three(stacks);

// while (stacks->size_b > 0)
// 	{
// 		int target = largest(stacks->stack_b, stacks->size_b);
// 		int idx = find_index(stacks->stack_b, stacks->size_b, target);
// 		if (idx <= stacks->size_b / 2)
// 			while (idx-- > 0)
// 				rb(stacks, 1);
// 		else
// 			for (int i = 0; i < stacks->size_b - idx; i++)
// 				rrb(stacks, 1);
// 		pa(stacks, 1);
// 	}
	
// 	int min_idx = find_index(stacks->stack_a, stacks->size_a, smallest(stacks->stack_a, stacks->size_a));
// 	if (min_idx <= stacks->size_a / 2)
// 	{
// 		while (min_idx-- > 0)
// 			ra(stacks, 1);
// 	}
// 	else
// 	{
// 		for (int i = 0; i < stacks->size_a - min_idx; i++)
// 			rra(stacks, 1);
// 	}
	


// 	// Push back from B to A in correct order
	

// 	// // Final rotate so smallest is at top
// 	// int min_val = smallest(stacks->stack_a, stacks->size_a);
// 	// int min_idx = find_index(stacks->stack_a, stacks->size_a, min_val);
// 	// if (min_idx <= stacks->size_a / 2)
// 	// 	while (min_idx-- > 0)
// 	// 		ra(stacks, 1);
// 	// else
// 	// 	for (int i = 0; i < stacks->size_a - min_idx; i++)
// 	// 		rra(stacks, 1);
// }


// void	push_swap(s_args *stacks)
// {
// 	int	*cost_arr;
// 	int	i;
// 	int	min_cost;
// 	int	min_value;
// 	int	max_val;
// 	int	max_idx;

// 	stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
// 	stacks->size_b = 0;
// 	pb(stacks, 1);
// 	pb(stacks, 1);
// 	while (stacks->size_a > 3)
// 	{
// 		cost_arr = malloc(sizeof(int) * stacks->size_a);
// 		for (i = 0; i < stacks->size_a; i++)
// 			cost_arr[i] = calc_cost_optimized(stacks, i);
// 		min_value = cost_arr[0];
// 		min_cost = 0;
// 		for (i = 1; i < stacks->size_a; i++)
// 		{
// 			if (cost_arr[i] < min_value)
// 			{
// 				min_value = cost_arr[i];
// 				min_cost = i;
// 			}
// 		}
// 		free(cost_arr);
// 		do_move(stacks, min_cost);
// 	}
// 	sort_three(stacks);
// 	while (stacks->size_b > 0)
// 	{
// 		max_val = largest(stacks->stack_b, stacks->size_b);
// 		max_idx = find_index(stacks->stack_b, stacks->size_b, max_val);
// 		if (max_idx <= stacks->size_b / 2)
// 			while (max_idx-- > 0)
// 				rb(stacks, 1);
// 		else
// 			for (int i = 0; i < stacks->size_b - max_idx; i++)
// 				rrb(stacks, 1);
// 		pa(stacks, 1);
// 		if (stacks->size_a > 1 && stacks->stack_a[0] > stacks->stack_a[1])
// 			sa(stacks, 1);
// 	}
// }
