/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:47:46 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/22 16:20:50 by kwrzosek         ###   ########.fr       */
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
    cost += find_index_in_a(stacks->stack_a, stacks->size_a, push_candidate);
    // if (i > stacks->size_a/2)
    //     cost = cost / 2;
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

// void cost_optimization(int min_cost, s_args *stacks)
// {
//     int b_index;
//     int a_index;
//     int push_nbr;
//     int move_counter;

//     push_nbr = stacks->stack_a[min_cost];
//     b_index = find_index_in_b(stacks->stack_b, stacks->size_b, push_nbr);
//     a_index = find_index_in_a(stacks->stack_a, stacks->size_a, push_nbr);


//     if (b_index == 0 && a_index == 0)
//         move_counter = 1;
//     else
//         move_counter = a_index + b_index;
//     printf("index_a: %i, index_b: %i\n", a_index, b_index);
//     printf("for number: %i expected cost: %i, counted cost: %i\n\n", push_nbr, min_cost, b_index + a_index);

// }

void push_swap(s_args *stacks)
{
    int cost;
    int i;
    int *cost_arr;
    int min_cost;

    int index_in_b;

    // to save cost, and then choose smallest one
    // cost_arr = malloc(sizeof(int) * stacks->size_a); 
    i = 0;
    stacks->stack_b = malloc(sizeof(int) * stacks->size_a);
    stacks->size_b = 0;
    pb(stacks, 1);
    pb(stacks, 1);

    // index of number with smallest cost
    while (stacks->size_a > 3)
    {
        cost_arr = malloc(sizeof(int) * stacks->size_a); 
        i = 0;
        while (i < stacks->size_a)
        {
            cost_arr[i] = calc_cost(stacks, i);
            // printf("cost for: %i: %i\n", stacks->stack_a[i], cost_arr[i]);
            i++;
        }
        
        min_cost = find_index(cost_arr, i, smallest(cost_arr, i));
        // cost_optimization(min_cost, stacks);
        index_in_b = find_index_in_b(stacks->stack_b, stacks->size_b, stacks->stack_a[min_cost]);

        // printf("pushed number: %i, cost: %i, index_in_b: %i\n", stacks->stack_a[min_cost], min_cost, index_in_b);
        int j = 0;
        i = 0;
       // rewrite this loop to optimize cost minimalizing cost 
        
        while (j < min_cost)
        {
            ra(stacks, 0);
            j++;
        }
        j = 0;
        while (j != index_in_b)
        {
            rb(stacks, 0);
            j++;
        }
        pb(stacks, 0);
        // printf("stack_b: %i\n", stacks->stack_b[]);
        free(cost_arr);
    }
    print_stacks(stacks);
}




// SEMI WORKING VERSION (SAVED FOR LATER)


    //     min_cost = find_index(cost_arr, i, smallest(cost_arr, i)); 
    //    index_in_b = find_index_in_b(stacks->stack_b, stacks->size_b, stacks->stack_a[min_cost]);
        
    //     // printf("min_cost: %i\n", min_cost);
    //     int j = 0;
    //     while (j != min_cost)
    //     {
    //         ra(stacks, 0);
    //         // print_stacks(stacks);
    //         j++;
    //     }
    //     // printf("top of stack_a: %i\n", stacks->stack_a[0]);

    //     j = 0;
    //     printf("index in b: %i\n", index_in_b);
    //     while (j != index_in_b)
    //     {
    //         rb(stacks, 0);
    //         // printf("top of stack_b: %i", stacks->stack_b[0]);
    //         // print_stacks(stacks);
    //         j++;
    //     }
    //     // printf("top of stack_b: %i\n", stacks->stack_b[0]);
        
    //     pb(stacks, 0);
    // }   
    // print_stacks(stacks);
