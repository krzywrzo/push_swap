/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:15:32 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 18:58:51 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
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

int	is_in_bounds(char **args)
{
	int		i;
	long	num;

	i = 0;
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
	int	i;
	int	j;

	i = 0;
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
	int	i;

	i = 0;
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
