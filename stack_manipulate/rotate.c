/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:11:29 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 13:51:35 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_args *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	printf("rr\n");
}

void	ra(t_args *stacks, int flag)
{
	int	i;
	int	first;

	i = 0;
	if (!stacks->stack_a || stacks->size_a <= 1)
		return ;
	first = stacks->stack_a[0];
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = first;
	if (flag == 1)
		printf("ra\n");
}

void	rb(t_args *stacks, int flag)
{
	int	i;
	int	first;

	i = 0;
	if (!stacks->stack_b || stacks->size_b <= 1)
		return ;
	first = stacks->stack_b[0];
	while (i < stacks->size_a - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = first;
	if (flag == 1)
		printf("rb\n");
}
