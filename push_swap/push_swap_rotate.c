/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:17:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:21:37 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_push_swap *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->value;
	while (stack->next && stack)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = temp;
}

void	ra(t_push_swap *stack_a)
{
	rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rb(t_push_swap *stack_b)
{
	rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rr(t_push_swap *stack_a, t_push_swap *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rrr\n", 4);
}
