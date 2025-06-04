/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:14 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/04 18:34:04 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(s_args *stacks)
{
	int	i;

	i = 0;
	printf("STACK A: \n");
	printf("size: %i\n", stacks->size_a);
	while (i < stacks->size_a)
	{
		printf("%i\n", stacks->stack_a[i]);
		i++;
	}
	i = 0;
	printf("STACK B: \n");
	printf("size: %i\n", stacks->size_b);
	while (i < stacks->size_b)
	{
		printf("%i\n", stacks->stack_b[i]);
		i++;
	}
}

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

void	free_stack(s_args *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
void	print_error(char **temp_stack, s_args *stacks, int flag)
{
	// if (flag == 0)
	// // ft_putstr_fd("Error\n", STDERR_FILENO);
	// 	// return (write(2, "Error\n", 6));
	// else if (flag == 1)
	// {
	// 	free_stack(stacks);
	// 	ft_putstr_fd("Error\n", STDERR_FILENO);
	// 	// return (write(2, "Error\n", 6));
	// }
	// else if (flag == 2)
	// {
	// 	free_stack(stacks);
	// 	free_split(temp_stack);
	// 	ft_putstr_fd("Error\n", STDERR_FILENO);
	// 	// return (write(2, "Error\n", 6));
	// }
	if (flag == 0)
	// ft_putstr_fd("Error\n", STDERR_FILENO);
		write(STDERR_FILENO, "Error\n", 6);
	else if (flag == 1)
	{
		free_stack(stacks);
		// ft_putstr_fd("Error\n", STDERR_FILENO);
		write(STDERR_FILENO, "Error\n", 6);

	}
	else if (flag == 2)
	{
		free_stack(stacks);
		free_split(temp_stack);
		// ft_putstr_fd("Error\n", STDERR_FILENO);
		write(STDERR_FILENO, "Error\n", 6);

	}
	exit(0);
}
