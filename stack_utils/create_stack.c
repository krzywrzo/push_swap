/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:54:15 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/09 18:54:24 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_args(int argc, char **argv)
{
	int		i;
	char	**temp_stack;

	temp_stack = malloc(sizeof(char *) * argc);
	if (!temp_stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp_stack[i - 1] = ft_strdup(argv[i]);
		if (!temp_stack[i - 1])
			return (NULL);
		i++;
	}
	temp_stack[argc - 1] = NULL;
	return (temp_stack);
}

int	*temp_to_stack(char **temp_stack, int stack_size)
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * stack_size);
	if (!stack)
	{
		free(stack);
		return (0);
	}
	i = 0;
	while (temp_stack[i])
	{
		stack[i] = (int)ft_atol(temp_stack[i]);
		i++;
	}
	return (stack);
}
