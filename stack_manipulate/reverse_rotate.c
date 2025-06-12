/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:35:06 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 13:50:08 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_args *stacks, int flag)
{
	int	last;
	int	i;

	if (stacks->stack_a == NULL || stacks->size_a <= 1)
		return ;
	last = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = last;
	if (flag == 1)
		printf("rra\n");
}

void	rrb(t_args *stacks, int flag)
{
	int	last;
	int	i;

	if (stacks->stack_b == NULL || stacks->size_b <= 1)
		return ;
	last = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = last;
	if (flag == 1)
		printf("rrb\n");
}

void	rrr(t_args *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	printf("rrr\n");
}
