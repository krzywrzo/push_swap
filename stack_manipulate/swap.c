/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:12:55 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 18:22:54 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_args *stacks, int flag)
{
	if (!stacks->stack_a || stacks->size_a < 2)
		return ;
	ft_swap(&stacks->stack_a[0], &stacks->stack_a[1]);
	if (flag == 1)
		printf("sa\n");
}

void	sb(t_args *stacks, int flag)
{
	if (!stacks->stack_b || stacks->size_b < 2)
		return ;
	ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
	if (flag == 1)
		printf("sb\n");
}

void	ss(t_args *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	printf("ss\n");
}
