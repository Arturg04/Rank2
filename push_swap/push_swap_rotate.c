/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:17:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 20:12:54 by ade-pinh         ###   ########.fr       */
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
	write(1, "ra\n", 3);
}

void	rb(t_swap *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_swap *stack_a, t_swap *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
