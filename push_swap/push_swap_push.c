/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:13:59 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/04 18:33:26 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_swap **stack_src, t_swap **stack_dest)
{
	t_swap	*temp;

	temp = *stack_dest;
	(*stack_dest) = (*stack_src);
	(*stack_src) = (*stack_src)->next;
	(*stack_dest)->next = temp;
}

void	pa(t_swap **stack_a, t_swap **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_swap **stack_a, t_swap **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
