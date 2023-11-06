/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:12:29 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/06 08:46:06 by ade-pinh         ###   ########.fr       */
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
}	t_swap;

// Utils
void	call_error(t_swap *stack);
void	free_stack(t_swap *_stack);

// Stack Utils
t_swap	*stack_last(t_swap *stack);
int		stack_length(t_swap *stack);
int		stack_min(t_swap *stack);
int		stack_max(t_swap *stack);
int		stack_index(t_swap *stack, int value);

// Commands
void	sa(t_swap *stack);
void	sb(t_swap *stack);
void	ss(t_swap *stack_a, t_swap *stack_b);
void	pa(t_swap **stack_a, t_swap **stack_b);
void	pb(t_swap **stack_a, t_swap **stack_b);
void	ra(t_swap *stack_a);
void	rb(t_swap *stack_b);
void	rr(t_swap *stack_a, t_swap *stack_b);
void	rra(t_swap *stack_a);
void	rrb(t_swap *stack_b);
void	rrr(t_swap *stack_a, t_swap *stack_b);

// Check
void	check_params(int ac, char	**av, t_swap *stack);
void	check_parameter(char *str, t_swap *stack);
int		check_sorted(t_swap *stack);

// Sort
void	sort_3(t_swap **stack);
void	sort(t_swap **stack_a);

void	push_swap(t_swap *stack_a);

int		rotate_type_ab(t_swap *a, t_swap *b);
int		rotate_type_ba(t_swap *a, t_swap *b);
int		next_a(t_swap *stack_b, int value_push);
int		next_b(t_swap *stack_b, int value_push);
int		apply_rarrb(t_swap **a, t_swap **b, int c, char s);
int		apply_rrarb(t_swap **a, t_swap **b, int c, char s);
int		apply_rrarrb(t_swap **a, t_swap **b, int c, char s);
int		apply_rarb(t_swap **a, t_swap **b, int c, char s);
int		case_rarb(t_swap *a, t_swap *b, int c);
int		case_rrarrb(t_swap *a, t_swap *b, int c);
int		case_rrarb(t_swap *a, t_swap *b, int c);
int		case_rarrb(t_swap *a, t_swap *b, int c);
int		case_rarb_a(t_swap *a, t_swap *b, int c);
int		case_rrarrb_a(t_swap *a, t_swap *b, int c);
int		case_rarrb_a(t_swap *a, t_swap *b, int c);
int		case_rrarb_a(t_swap *a, t_swap *b, int c);


#endif
