/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:17:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 04:04:08 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_swap *stack)
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

void	ra(t_swap *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 4);
}

void	rb(t_swap *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 4);
}

void	rr(t_swap *stack_a, t_swap *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 4);
}
