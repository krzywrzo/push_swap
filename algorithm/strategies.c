/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:00:55 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 13:50:56 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_cost *cost, t_args *stacks)
{
	while (cost->ra_count > 0 && cost->rb_count > 0)
	{
		rr(stacks);
		cost->ra_count--;
		cost->rb_count--;
	}
	while (cost->ra_count-- > 0)
		ra(stacks, 1);
	while (cost->rb_count-- > 0)
		rb(stacks, 1);
}

void	reverse_rotate(t_cost *cost, t_args *stacks)
{
	while (cost->rra_count > 0 && cost->rrb_count > 0)
	{
		rrr(stacks);
		cost->rra_count--;
		cost->rrb_count--;
	}
	while (cost->rra_count-- > 0)
		rra(stacks, 1);
	while (cost->rrb_count-- > 0)
		rrb(stacks, 1);
}

void	ra_rrb(t_cost *cost, t_args *stacks)
{
	while (cost->ra_count-- > 0)
		ra(stacks, 1);
	while (cost->rrb_count-- > 0)
		rrb(stacks, 1);
}

void	rra_rb(t_cost *cost, t_args *stacks)
{
	while (cost->rra_count-- > 0)
		rra(stacks, 1);
	while (cost->rb_count-- > 0)
		rb(stacks, 1);
}
