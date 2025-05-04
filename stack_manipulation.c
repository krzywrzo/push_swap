/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:28 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/04 15:06:15 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(int *stack, int flag)
{
	if (!stack[0] || !stack[1])
		printf("To few elements in stack, operation not possible");
	else
		ft_swap(&stack[0], &stack[1]);
	if (flag == 1)
		printf("sa\n");
}

void sb(int *stack, int flag)
{
	if (!stack[0] || !stack[1])
		printf("To few elements in stack, operation not possible");
	else
		ft_swap(&stack[0], &stack[1]);
	if (flag == 1)
		printf("sb\n");
}

void ss(int *stack_a, int *stack_b, int flag)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	printf("ss\n");
}

void rr(int *stack_a, int *stack_b, int size_a, int size_b, int flag)
{
	ra(stack_a, size_a, 0);
	ra(stack_b, size_b, 0);
	printf("rr\n");
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b, int flag)
{
	rra(stack_a, size_a, 0);
	rra(stack_b, size_b, 0);
	printf("rrr\n");
}

void ra(int *stack, int ssize, int flag)
{
	int	i;

	i = 0;
	while (i < ssize - 1)
	{
		ft_swap(&stack[i], &stack[i + 1]);
		i++;
	}
	if (flag == 1)
		printf("ra\n");
}

void rb(int *stack, int ssize, int flag)
{
	int	i;

	i = 0;
	while (i < ssize - 1)
	{
		ft_swap(&stack[i], &stack[i + 1]);
		i++;
	}
	if (flag == 1)
		printf("rb\n");
}

void rra(int *stack, int ssize, int flag)
{
    if (stack == NULL || ssize <= 1)
        return;

    int last = stack[ssize - 1]; 
    int i = ssize - 1;

    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = last;
	if (flag == 1)
		printf("rra\n");
}

void rrb(int *stack, int ssize, int flag)
{
	if (stack == NULL || ssize <= 1)
	return;

	int last = stack[ssize - 1]; 
	int i = ssize - 1;

	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = last;
	if (flag == 1)
		printf("rrb\n");
}

void pb(int *stack_a, int *stack_b, int *size_a, int *size_b, int flag)
{
    int i;

    if (*size_a == 0)
    {
        printf("Stack A is empty, cannot perform pb\n");
        return;
    }
    i = *size_b;
    while (i > 0)
    {
        stack_b[i] = stack_b[i - 1];
        i--;
    }
    stack_b[0] = stack_a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    (*size_a)--;
    (*size_b)++;
	if (flag == 1)
		printf("pb/n");
}
void pa(int *stack_a, int *stack_b, int *size_a, int *size_b, int flag)
{
    int i;

    if (*size_b == 0)
    {
        printf("Stack B is empty, cannot perform pa\n");
        return;
    }
    i = *size_a;
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[0] = stack_b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    (*size_b)--;
    (*size_a)++;
	if (flag == 1)
		printf("pb\n");
}