/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:15:32 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/05 18:32:04 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid(int *stack, int arr_size)
{
    int i; 
    int j;

    j = 0;
    i = 0;
    while (i < arr_size)
    {
        j = 0;
        while (j < arr_size)
        {
            if (j == i)
                j++;
            if (stack[j] == stack[i])
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}