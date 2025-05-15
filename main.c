/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:59 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/15 17:13:40 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(s_args *stacks)
{
    int i = 0;
    printf("STACK A: \n");
    printf("size: %i\n", stacks->size_a);
    while(i < stacks->size_a)
    {
        printf("%i\n", stacks->stack_a[i]);
        i++;
    }

    i = 0;
    printf("STACK B: \n");
    printf("size: %i\n", stacks->size_b);
    while(i < stacks->size_b)
    {
        printf("%i\n", stacks->stack_b[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    s_args *stacks;
    char **temp_stack;

    stacks = malloc(sizeof(s_args));
    if (!stacks)
        return (0);
    stacks->size_a = argc - 1;
    temp_stack = malloc(sizeof(char *) * stacks->size_a);
    if (argc == 1)
    {
        printf("to few arguments");
        return (1);
    }
    else if (argc == 2)
    {
        temp_stack = ft_split(argv[1], ' ');
        stacks->size_a = stack_size(temp_stack);
        // printf("size: %i", stacks->size_a);
    }
    else
        temp_stack = copy_args(argc, argv);
    stacks->stack_a = temp_to_stack(temp_stack, stacks->size_a);
    free_split(temp_stack);
    if (is_valid(stacks->stack_a, stacks->size_a) == 1)
    {
        printf("There are duplicates in your stack");
        return(1);
    }
    push_swap(stacks);
    // print_stacks(stacks);
    // free(stacks);
}

