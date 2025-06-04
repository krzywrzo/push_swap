/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:28 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/04 16:16:13 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(s_args *stacks, int flag)
{
	if (!stacks->stack_a || !stacks->stack_a[0] || !stacks->stack_a[1])
	{
		printf("to few elements in stack to perform");
		return ;
	}
	else
		ft_swap(&stacks->stack_a[0], &stacks->stack_a[1]);
	if (flag == 1)
		printf("sa\n");
}

void	sb(s_args *stacks, int flag)
{
	if (!stacks->stack_a || !stacks->stack_b[0] || !stacks->stack_b[1])
	{
		printf("to few elements in stack to perform");
		return ;
	}
	else
		ft_swap(&stacks->stack_b[0], &stacks->stack_b[1]);
	if (flag == 1)
		printf("sb\n");
}

void	ss(s_args *stacks, int flag)
{
	sa(stacks, 0);
	sb(stacks, 0);
	printf("ss\n");
}

void	rr(s_args *stacks, int flag)
{
	ra(stacks, 0);
	ra(stacks, 0);
	printf("rr\n");
}

void	rrr(s_args *stacks, int flag)
{
	rra(stacks, 0);
	rra(stacks, 0);
	printf("rrr\n");
}

void	ra(s_args *stacks, int flag)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (!stacks->stack_a || stacks->size_a <= 1)
		{
			printf("to few elements in stack to perform");
			return ;
		}
		ft_swap(&stacks->stack_a[i], &stacks->stack_a[i + 1]);
		i++;
	}
	if (flag == 1)
		printf("ra\n");
}

void	rb(s_args *stacks, int flag)
{
	int	i;

	i = 0;
	while (i < stacks->size_b - 1)
	{
		ft_swap(&stacks->stack_b[i], &stacks->stack_b[i + 1]);
		i++;
	}
	if (flag == 1)
		printf("rb\n");
}

void	rra(s_args *stacks, int flag)
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

void	rrb(s_args *stacks, int flag)
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

void	pb(s_args *args, int flag)
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

void	pa(s_args *args, int flag)
{
	int	i;

	if (args->size_b == 0)
	{
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
