/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/13 13:27:48 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost (s_args *stacks)
{
    int cost = 0; 
    int largest_b;
    int i;

    largest_b = largest(stacks->stack_b, stacks->size_b);
    cost = 0;
    while (i < stacks->size_a)
    {
        cost += find_index(stacks->stack_a, stacks->size_a);
        i++;
    }
    return (cost);
}

void push_swap(s_args *stacks)
{
    int cost;
    int min_cost;
    
    stacks->size_b = stack_size(stacks->stack_b);
    pb(stacks, 1);
    pb(stacks, 1);
    printf("cost: %i", calc_cost(stacks));    
}