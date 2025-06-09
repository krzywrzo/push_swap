/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:15:32 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 11:45:20 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	int	i = 0;

	if (!str || *str == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign = 1;
	long	result = 0;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

int	is_in_bounds(char **args)
{
	int		i = 0;
	long	num;

	while (args[i])
	{
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	has_duplicates(int *stack, int size)
{
	int	i = 0;
	int	j;

	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_input(char **args)
{
	int i = 0;

	while (args[i])
	{
		if (is_numeric(args[i]) == 1)
			return (1);
		i++;
	}
	if (is_in_bounds(args) == 1)
		return (1);
	return (0);
}


int	is_valid_stack(int *stack, int size)
{
	if (has_duplicates(stack, size) == 1)
		return (1);
	return (0);
}
