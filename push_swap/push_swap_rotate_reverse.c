/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:17:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:23:40 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_push_swap *_stack)
{
	int			temp1;
	int			temp2;
	t_push_swap	*stack_ptr;

	if (!_stack)
		return ;
	stack_ptr = _stack;
	temp1 = _stack->value;
	while (_stack && _stack->next)
	{
		temp2 = _stack->next->value;
		_stack->next->value = temp1;
		_stack = _stack->next;
		temp1 = temp2;
	}
	stack_ptr->value = temp1;
}

void	rra(t_push_swap *stack_a)
{
	rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_push_swap *stack_b)
{
	rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push_swap *stack_a, t_push_swap *stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
