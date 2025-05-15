/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/15 21:14:01 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost (s_args *stacks)
{
    int min_cost;
    int cost; 
    int i;
    int push_candidate;

    // cost = 0;
    i = 0;
    while (i < stacks->size_a)
    {
        // cost counting (without optimalization)
        cost = 0;
        push_candidate = stacks->stack_a[i];
        cost = find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
        cost += i;
        if (i > stacks->size_a/2)
            cost = cost / 2;
        // printf("for: %i, cost: %i\n", push_candidate, cost);
        i++;
    }
    return (cost);
}


void push_swap(s_args *stacks)
{
    int cost;
    int min_cost;
    stacks->stack_b = malloc(stacks->size_a);
    stacks->size_b = 0;
    pb(stacks, 1);
    pb(stacks, 1);

    calc_cost(stacks);
//    printf("cost: %i",calc_cost(stacks));
}
