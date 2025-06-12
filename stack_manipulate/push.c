/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:13:30 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 18:20:12 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_args *args, int flag)
{
	int	i;

	if (args->size_a == 0)
	{
		return ;
	}
	i = args->size_b;
	while (i > 0)
	{
		args->stack_b[i] = args->stack_b[i - 1];
		i--;
	}
	args->stack_b[0] = args->stack_a[0];
	i = 0;
	while (i < args->size_a - 1)
	{
		args->stack_a[i] = args->stack_a[i + 1];
		i++;
	}
	args->size_a--;
	args->size_b++;
	if (flag == 1)
		printf("pb\n");
}

void	pa(t_args *args, int flag)
{
	int	i;

	if (args->size_b == 0)
	{
		return ;
	}
	i = args->size_a;
	while (i > 0)
	{
		args->stack_a[i] = args->stack_a[i - 1];
		i--;
	}
	args->stack_a[0] = args->stack_b[0];
	i = 0;
	while (i < args->size_b - 1)
	{
		args->stack_b[i] = args->stack_b[i + 1];
		i++;
	}
	args->size_b--;
	args->size_a++;
	if (flag == 1)
		printf("pa\n");
}
