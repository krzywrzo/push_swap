/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:40:42 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/13 13:18:05 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int largest(int *stack, int stack_size)
{
    int i;
    int max;

    i = 0;
    max = stack[0];
    while (i<stack_size)
    {
        if (max < stack[i])
            max = stack[i];
        i++;
    }
    return (max);
}

int    find_index(int *stack, int size)
{
    int largest_num; 
    int index;
    int i; 

    i = 0;
    largest_num = largest(stack, size);
    while (i < size)
    {
        if (largest_num == stack[i])
            return(index);
        i++;
    }
    return(index);
}