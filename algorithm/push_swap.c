/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/14 18:38:59 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost (s_args *stacks)
{
    int cost;
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

    stacks->size_b = 0;
    pb(stacks, 1);
    stacks->size_b++;
    pb(stacks, 1);
    stacks->size_b++;

    printf("cost: %i", calc_cost(stacks));
}
