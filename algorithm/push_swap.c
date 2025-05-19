/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/19 18:08:47 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_cost (s_args *stacks, int i)
{
    
    int push_candidate;
    int cost; 

    cost = 0;
    push_candidate = stacks->stack_a[i];
    cost += find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
    cost += i;
    if (i > stacks->size_a/2)
        cost = cost / 2;
    return (cost);
    /*
    int min_cost;
    int cost; 
    int i;
    int push_candidate;

    // cost = 0;
    i = 0;
    // while (i < stacks->size_a)
    // {
        // cost counting (without optimalization)
        cost = 0;
        push_candidate = stacks->stack_a[i];
        cost = find_index_in_b(stacks->stack_b, stacks->size_b, push_candidate);
        cost += i; // because index in stack_a = number of rotation needed to put it on top
        if (i > stacks->size_a/2)
            cost = cost / 2;
        // printf("for: %i, cost: %i\n", push_candidate, cost);
        // i++;
    // }
    return (cost);
    */
}

void push_swap(s_args *stacks)
{
    int cost;
    int i;
    int *cost_arr;
    int min_cost;

    // to save cost, and then choose smallest one
    cost_arr = malloc(sizeof(int) * stacks->size_a); 
    i = 0;
    stacks->stack_b = malloc(stacks->size_a);
    stacks->size_b = 0;
    pb(stacks, 1);
    pb(stacks, 1);
    while (i < stacks->size_a)
    {
        cost_arr[i] = calc_cost(stacks, i);
        i++;
    }

    // index of number with smallest cost
    min_cost = find_index(cost_arr, i, smallest(cost_arr, i)); 
  
    /*
    printf("min cost: %i", min_cost);
    printing cost array 
    int j = 0;
    while (j < stacks->size_a)
    {
        printf("for: %i cost: %i\n", stacks->stack_a[j], cost_arr[j]);
        j++;
    }
    */
}
