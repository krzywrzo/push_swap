/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:21:05 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/10 16:36:42 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cost_struct_filler(t_cost *cost, t_args *stacks, int a_index, int b_index)
{
	
	cost->ra_count = a_index;
	cost->rb_count = b_index;
	if (a_index == 0)
		cost->rra_count = 0;
	else
		cost->rra_count = stacks->size_a - a_index;
	if (b_index == 0)
		cost->rrb_count = 0;
	else
		cost->rrb_count = stacks->size_b - b_index;
	cost->cost_rr = max(cost->ra_count, cost->rb_count);
	cost->cost_rrr = max(cost->rra_count, cost->rrb_count);
	cost->cost_ra_rrb = cost->ra_count + cost->rrb_count;
	cost->cost_rra_rb = cost->rra_count + cost->rb_count;
}

int	calc_strategy(t_cost *cost)
{
	int	strategy;

	if (cost->cost_rrr < cost->min_cost)
	{
		cost->min_cost = cost->cost_rrr;
		strategy = 1;
	}
	if (cost->cost_ra_rrb < cost->min_cost)
	{
		cost->min_cost = cost->cost_ra_rrb;
		strategy = 2;
	}
	if (cost->cost_rra_rb < cost->min_cost)
	{
		cost->min_cost = cost->cost_rra_rb;
		strategy = 3;
	}
	return(strategy);
}

void	perform_strategy(t_cost *cost, t_args *stacks, int strategy)
{
	if (strategy == 0)  // rr
		rotate(cost, stacks);
	else if (strategy == 1)  // rrr
		reverse_rotate(cost, stacks);
	else if (strategy == 2) 
		ra_rrb(cost, stacks);
	else if (strategy == 3) 
		rra_rb(cost, stacks);
	pb(stacks, 1);
}
void	calc_cost(t_cost *cost, t_args *stacks, int a_index, int b_index)
{
	if (a_index == 0)
		cost->rra_count = 0;
	else
		cost->rra_count = stacks->size_a - a_index;
	if (b_index == 0)
		cost->rrb_count = 0;
	else
		cost->rrb_count = stacks->size_b - b_index;
	cost->cost_rr = max(a_index, b_index);
	cost->cost_rrr = max(cost->rra_count, cost->rrb_count);
	cost->cost_ra_rrb = a_index + cost->rrb_count;
	cost->cost_rra_rb = cost->rra_count + b_index;
	cost->min_cost = cost->cost_rr;
	cost->min_cost = min(cost->min_cost, cost->cost_rrr);
	cost->min_cost = min(cost->min_cost, cost->cost_ra_rrb);
	cost->min_cost = min(cost->min_cost, cost->cost_rra_rb);
}


// rev_a --> rra_count
// rev_b --> rrb_count