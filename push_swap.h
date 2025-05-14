/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:07 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/14 18:21:16 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct t_args
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}		s_args;

// funtions for stack manipulation
// Push operations
void	pa(s_args *args, int flag);
void	pb(s_args *args, int flag);

// Rotate operations
void	rra(s_args *args, int flag);
void	rrb(s_args *args, int flag);
void	ra(s_args *args, int flag);
void	rb(s_args *args, int flag);
void	rrr(s_args *args, int flag);
void	rr(s_args *args, int flag);

// Swap operations
void	ss(s_args *args, int flag);
void	sa(s_args *args, int flag);
void	sb(s_args *args, int flag);

// stack manipulation utils
int		is_valid(int *stack, int arr_size);
void	ft_swap(int *a, int *b);
int		stack_size(char **arr);
void	free_split(char **arr);
char	*fill_stack(char *filler_values, char *stack);
char	**copy_args(int argc, char **argv);
int		*temp_to_stack(char **temp_stack, int stack_size);
int		largest(int *stack, int stack_size);

// push swap functions
void	push_swap(s_args *stacks);
int		calc_cost(s_args *stacks);
int		largest(int *stack, int stack_size);
int		find_index(int *stack, int size);
#endif
