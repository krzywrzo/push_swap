/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:55:07 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/12 13:52:19 by kwrzosek         ###   ########.fr       */
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
}		t_args;

typedef struct t_cost
{
	int	b_index;
	int	ra_count;
	int	rb_count;
	int	rra_count; // rev_a
	int	rrb_count; // rev_b
	int	cost_rr;
	int	cost_rrr;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	min_cost;
}		t_cost;

/*  STACK_MANIPULATE    */
// push.c
void	pa(t_args *args, int flag);
void	pb(t_args *args, int flag);
// rotate.c
void	rra(t_args *args, int flag);
void	rrb(t_args *args, int flag);
void	ra(t_args *args, int flag);
void	rb(t_args *args, int flag);
void	rrr(t_args *args);
void	rr(t_args *args);
// swap.c
void	ss(t_args *args);
void	sa(t_args *args, int flag);
void	sb(t_args *args, int flag);
// stack_manipulate_utils.c
void	ft_swap(int *a, int *b);
int		stack_size(char **arr);
void	free_split(char **arr);
void	free_stack(t_args *stacks, t_cost *cost);
void	print_error(char **temp_stack, t_args *stacks, t_cost *cost, int flag);

/*  ALGORITHM   */
// alg_utils.c
int		largest(int *stack, int size);
int		smallest(int *stack, int size);
//  cost_utils.c
void	cost_struct_filler(t_cost *cost, t_args *stacks, int a_index,
			int b_index);
int		calc_strategy(t_cost *cost);
void	perform_strategy(t_cost *cost, t_args *stacks, int strategy);
void	calc_cost(t_cost *cost, t_args *stacks, int a_index, int b_index);
// find_index.c
int		find_index(int *stack, int size, int num);
int		find_index_in_a(int *stack_a, int size_a, int candidate);
int		find_index_in_b(int *stack_b, int size_b, int value);
// push_swap_utils.c
int		max(int a, int b);
int		min(int a, int b);
int		is_sorted(int *stack, int size);
int		calc_min_cost(t_args *stacks, t_cost *cost);
void	push_a(t_args *cost);
// push_swap.c
int		calc_cost_optimized(t_args *stacks, t_cost *cost, int a_index);
void	do_move(t_args *stacks, t_cost *cost, int a_index);
void	sort_three(t_args *stacks);
void	push_swap(t_args *stacks, t_cost *cost);
// strategies.c
void	rotate(t_cost *cost, t_args *stacks);
void	reverse_rotate(t_cost *cost, t_args *stacks);
void	ra_rrb(t_cost *cost, t_args *stacks);
void	rra_rb(t_cost *cost, t_args *stacks);

/*  STACK_UTILS */
//  create_stacks.c
char	**copy_args(int argc, char **argv);
int		*temp_to_stack(char **temp_stack, int stack_size);
//	stack_validate.c
int		is_numeric(char *str);
int		is_in_bounds(char **args);
int		has_duplicates(int *stack, int size);
int		is_valid_input(char **args);
int		is_valid_stack(int *stack, int size);

/*  MAIN    */
int		main(int argc, char **argv);
void	print_stacks(t_args *stacks);

#endif
