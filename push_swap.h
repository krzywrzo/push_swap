/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:07 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/04 20:00:26 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
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
// int		is_valid(int *stack, int arr_size);
int		is_valid(char **temp_stack);
void	ft_swap(int *a, int *b);
int		stack_size(char **arr);
void	free_split(char **arr);
void	free_stack(s_args *stacks);
char	*fill_stack(char *filler_values, char *stack);
char	**copy_args(int argc, char **argv);
int		*temp_to_stack(char **temp_stack, int stack_size);

// push swap functions
void	push_swap(s_args *stacks);
int		calc_cost(s_args *stacks, int i);
int		find_index_in_b(int *stack_b, int size_b, int push_candidate);
int		find_index_in_a(int *stack_a, int size_a, int push_candidate);
int		find_index(int *stack, int size, int num);
void	sort_three(s_args *stacks);

// algorithm utils
int		which_smaller(int a, int b);
int		largest(int *stack, int size);
int		smallest(int *stack, int size);
int		abs(int a);

void	rotate(s_args *stacks, int a_index, int b_index);
void	mixed_rotate(s_args *stacks, int a_index, int b_index);
void	reverse_rotate(s_args *stacks, int a_index, int b_index);
void	mixed_rrotate(s_args *stacks, int a_index, int b_index);

void	print_stacks(s_args *stacks);
void		print_error(char **temp_stack, s_args *stacks, int flag);
#endif
