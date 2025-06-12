/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 14:08:42 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost_optimized(t_args *stacks, t_cost *cost, int a_index)
{
	int	push_candidate;
	int	b_index;

	push_candidate = stacks->stack_a[a_index];
	b_index = find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
	calc_cost(cost, stacks, a_index, b_index);
	return (cost->min_cost + 1);
}

void	do_move(t_args *stacks, t_cost *cost, int a_index)
{
	int	b_index;
	int	strategy;

	b_index = 0;
	if (b_index == stacks->size_b)
		b_index = 0;
	b_index = find_index_in_b(stacks->stack_b, stacks->size_b,
			stacks->stack_a[a_index]);
	cost_struct_filler(cost, stacks, a_index, b_index);
	cost->min_cost = cost->cost_rr;
	strategy = 0;
	strategy = calc_strategy(cost);
	perform_strategy(cost, stacks, strategy);
}

void	sort_three(t_args *stacks)
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

void	push_swap(t_args *stacks, t_cost *cost)
{
	int	min_cost;

	stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
	stacks->size_b = 0;
	if(is_sorted(stacks->stack_a, stacks->size_a))
		exit(0);
	pb(stacks, 1);
	pb(stacks, 1);
	printf("test");
	while (stacks->size_a > 3)
	{
		min_cost = calc_min_cost(stacks, cost);
		do_move(stacks, cost, min_cost);
	}
	sort_three(stacks);
	push_a(stacks);
	while (!is_sorted(stacks->stack_a, stacks->size_a))
		ra(stacks, 1);
}
