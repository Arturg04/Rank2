/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:23:20 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:23:32 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_push_swap *stack)
{
	int	temp;

	if (!stack)
		return ;
	temp = stack->next->value;
	stack->next->value = stack->value;
	stack->value = temp;
}

void	sa(t_push_swap *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_push_swap *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	ss(t_push_swap *stack_a, t_push_swap *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
