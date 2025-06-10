/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:14 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/10 17:04:52 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	stack_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_args *stacks, t_cost *cost)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	free(cost);
}

void	print_error(char **temp_stack, t_args *stacks, t_cost *cost, int flag)
{
	if (flag == 0)
		write(STDERR_FILENO, "Error\n", 6);
	else if (flag == 1)
	{
		free_stack(stacks, cost);
		write(STDERR_FILENO, "Error\n", 6);
	}
	else if (flag == 2)
	{
		free_stack(stacks, cost);
		free_split(temp_stack);
		write(STDERR_FILENO, "Error\n", 6);
	}
	exit(0);
}
