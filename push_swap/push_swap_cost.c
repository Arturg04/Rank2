/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:39:02 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 01:54:10 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_cost	only_rotate(t_push_swap *stack)
{
	t_cost _cost;

	_cost = inicialize_cost();
	while (stack && stack->next)
	{
		if (stack->next->value < stack->value)
			break ;
		stack = stack->next;
		_cost.ra++;
	}
	_cost.ra++;
	stack = stack->next;
	while (stack && stack->next)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		_cost.rra++;
	}
	_cost.rra++;
	return (_cost);
}


