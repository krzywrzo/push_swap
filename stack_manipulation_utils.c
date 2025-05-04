/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:14 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/03 11:55:16 by kwrzosek         ###   ########.fr       */
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

size_t stack_size(int *stack)
{
    int i;

    i = 0;
    while(stack[i])
    {
        i++;
    }
    return (i);
}
