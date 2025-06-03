/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:14 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/03 18:56:37 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int stack_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

void free_split(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void    free_stack(s_args *stacks)
{
    free(stacks->stack_a);
    free(stacks->stack_b);
    free(stacks);
}
int print_error()
{
    write(2, "Error\n", 6);
    return (0);
}
