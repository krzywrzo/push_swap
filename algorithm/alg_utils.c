/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:40:42 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/10 17:08:21 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	largest(int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (i < size)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

int	smallest(int *stack, int size)
{
	int	i;
	int	min;

	i = 1;
	min = stack[0];
	while (i < size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}
