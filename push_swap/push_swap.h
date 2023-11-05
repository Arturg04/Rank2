/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:12:29 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 01:57:56 by ade-pinh         ###   ########.fr       */
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
	int				cost;
	struct s_swap	*next;
}	t_swap;

// Utils
void	call_error(t_swap *stack);
void	free_stack(t_swap *_stack);
void	print_stacks(t_swap *_stack_a, t_swap *_stack_b);

// Stack Utils
int		stack_length(t_swap *stack);
int		stack_min(t_swap *stack);
int		stack_max(t_swap *stack);
int		stack_index(t_swap *stack, int value);
int		stack_next(t_swap *stack, int value);

// Commands
void	sa(t_swap *stack);
void	sb(t_swap *stack);
void	ss(t_swap *stack_a, t_swap *stack_b);
void	pa(t_swap **stack_a, t_swap **stack_b);
void	pb(t_swap **stack_b, t_swap **stack_a);
void	ra(t_swap *stack_a);
void	rb(t_swap *stack_b);
void	rr(t_swap *stack_a, t_swap *stack_b);
void	rra(t_swap *stack_a);
void	rrb(t_swap *stack_b);
void	rrr(t_swap *stack_a, t_swap *stack_b);

// Check
void	check_params(int ac, char	**av, t_swap *stack);
void	check_parameter(char *str, t_swap *stack);
int		check_order(t_swap *stack);
int		check_solution(t_swap *stack_a, t_swap *stack_b);

// Sort
void	sort_3(t_swap **stack);
void	sort_5(t_swap **stack_a, t_swap **stack_b);
void	sort(t_swap **stack_a, t_swap **stack_b);

void	send_object(t_swap **stack_a, t_swap **stack_b, int value);

// Cost
void	get_cost(t_swap *stack_a, t_swap *stack_b);
int		least_cost(t_swap *stack);
int		cost_rotate(int length, int index);

void	push_swap(t_swap *stack_a, t_swap *stack_b);

#endif
