/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:17:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 04:03:48 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_swap *stack)
{
	int		temp1;
	int		temp2;
	t_swap	*stack_ptr;

	if (!stack)
		return ;
	stack_ptr = stack;
	temp1 = stack->value;
	while (stack && stack->next)
	{
		temp2 = stack->next->value;
		stack->next->value = temp1;
		stack = stack->next;
		temp1 = temp2;
	}
	stack_ptr->value = temp1;
}

void	rra(t_swap *stack_a)
{
	rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_swap *stack_b)
{
	rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_swap *stack_a, t_swap *stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
