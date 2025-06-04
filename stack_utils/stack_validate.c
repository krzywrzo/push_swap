/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:15:32 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/04 20:55:59 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_valid(int *stack, int arr_size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (!stack || arr_size <= 0)
// 		return (1); // Error: Invalid stack or size
// 	while (i < arr_size)
// 	{
// 		j = 0;
// 		while (j < arr_size)
// 		{
// 			if (i == j)
// 				j++;
// 			if (stack[i] == stack[j])
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

double ft_atol(char *str)
{
	long i;
	double f;
	double pow;
	int sign;

	i = 0;
	f = 0;
	sign = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		str++;
	while ('+' == *str || '-' == *str)
		if (*str == '-')
			sign = -sign;
	while (*str != '.' && *str)
		i = (i * 10) + (*str - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		f = f + (*str++ - 48) * pow;
	}
	return ((i + f) * sign);
}
int is_in_bounds (char **temp_stack)
{
	long	num = ft_atol(*temp_stack);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int is_duplicate (char **temp_stack)
{
	int i;
	int j;

	i = 0;
	int size = stack_size(temp_stack);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				j++;
			if (temp_stack[i] == temp_stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid(char **temp_stack)
{
	if (!temp_stack)
		return (1);
	 if (is_duplicate(temp_stack) == 1)
		return (1);
	else if (is_in_bounds(temp_stack) == 1)
		return (1);
	return (0);
}
