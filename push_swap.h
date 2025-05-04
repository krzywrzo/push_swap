/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:07 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/04 15:06:17 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>

#include "libft/libft.h"

char    *fill_stack(char *filler_values, char *stack);
char    **copy_args(int argc, char **argv);
int     *temp_to_stack(char **temp_stack, int stack_size);

// funtions for stack manipulation
void pa(int *stack_a, int *stack_b, int *size_a, int *size_b, int flag);
void pb(int *stack_a, int *stack_b, int *size_a, int *size_b, int flag);

void rra(int *stack, int ssize, int flag);
void rrb(int *stack, int ssize, int flag);
void ra(int *stack, int ssize, int flag);
void rb(int *stack, int ssize, int flag);
void rrr(int *stack_a, int *stack_b, int size_a, int size_b, int flag);
void rr(int *stack_a, int *stack_b, int size_a, int size_b, int flag);

void ss(int *stack_a, int *stack_b, int flag);
void sa(int *stack, int flag);
void sb(int *stack, int flag);

// stack manipulation utils 
void    ft_swap(int *a, int *b);
size_t     stack_size(int *stack);
#endif