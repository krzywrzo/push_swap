/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:15:32 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/14 14:57:27 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid(int *stack, int arr_size)
{
    int i = 0;
    int j;

    if (!stack || arr_size <= 0)
        return (1); // Error: Invalid stack or size

    while (i < arr_size - 1)
    {
        j = i + 1;
        while (j < arr_size)
        {
            if (stack[i] == stack[j])
                return (1); // Duplicate found
            j++;
        }
        i++;
    }
    return (0);
}
