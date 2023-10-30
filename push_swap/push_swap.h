/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:12:29 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/30 19:53:50 by ade-pinh         ###   ########.fr       */
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
void	pa(t_push_swap **stack_a, t_push_swap **stack_b);
void	pb(t_push_swap **stack_b, t_push_swap **stack_a);
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
void	sort_5(t_push_swap *stack_a, t_push_swap *stack_b);

void	push_swap(t_push_swap *stack_a, t_push_swap *stack_b);


#endif
