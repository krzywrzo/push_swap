/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:59 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/05 18:34:20 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int stack_size;
    char **temp_stack; 

    stack_size = argc - 1;
    temp_stack = malloc(sizeof(char *) * stack_size);
    if (argc == 1)
    {
        printf("to few arguments");
        return (0);
    }
    else if (argc == 2)
    {
        temp_stack = ft_split(argv[1], ' ');
        stack_size = ft_strlen(*temp_stack);
    }
    else
		temp_stack = copy_args(argc, argv);
	stack_a = temp_to_stack(temp_stack, stack_size);
	free(temp_stack);
    if (is_valid(stack_a, stack_size) == 1)
    {
        printf("There are duplicates in your stack");
        return (0);
    }
    stack_b = malloc(sizeof(int) * stack_size);
    return (0);
}