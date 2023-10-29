/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:12:29 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 22:13:39 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_swap
{
	int				value;
	struct s_swap	*next;
}	t_push_swap;

typedef struct s_cost
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_cost;

// Utils
void	call_error(t_push_swap *stack);
void	free_stack(t_push_swap *_stack);
void	print_stacks(t_push_swap *_stack_a, t_push_swap *_stack_b);

// Stack Utils
int	stack_length(t_push_swap *stack);
int	stack_min(t_push_swap *stack);
int	stack_max(t_push_swap *stack);

// Commands
void	sa(t_push_swap *stack);
void	sb(t_push_swap *stack);
void	ss(t_push_swap *stack_a, t_push_swap *stack_b);
void	pa(t_push_swap *stack_a, t_push_swap *stack_b);
void	pb(t_push_swap *stack_b, t_push_swap *stack_a);
void	ra(t_push_swap *stack_a);
void	rb(t_push_swap *stack_b);
void	rr(t_push_swap *stack_a, t_push_swap *stack_b);
void	rra(t_push_swap *stack_a);
void	rrb(t_push_swap *stack_b);
void	rrr(t_push_swap *stack_a, t_push_swap *stack_b);

// Check
void	check_params(int ac, char	**av, t_push_swap *stack);
void	check_parameter(char *str, t_push_swap *stack);
int		check_order(t_push_swap *stack);
int		check_solution(t_push_swap *stack_a, t_push_swap *stack_b);

// Sort
void	sort_3(t_push_swap *stack);
void	sort(t_push_swap *stack_a, t_push_swap *stack_b, int total);



void	push_swap(t_push_swap *stack_a, t_push_swap *stack_b, int total);
void	divide_in_stacks(t_push_swap **stack_a, t_push_swap **stack_b, int size);
void	select_move(t_push_swap *stack_a, t_push_swap *stack_b, t_cost cost);


// Cost of moves
t_cost	get_cost(t_push_swap *stack_a, t_push_swap *stack_b);
t_cost	inicialize_cost(void);
int		least_cost(t_cost cost);
t_cost	only_rotate(t_push_swap *stack);


#endif
