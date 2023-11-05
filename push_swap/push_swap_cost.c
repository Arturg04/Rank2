/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:19 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/04 23:46:02 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_rotate(int length, int index)
{
	int	cost;

	if (index < length / 2)
		cost = index;
	else
		cost = length - index;
	return (cost);
}

static int	cost(int length_a, int index_a, int length_b, int index_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_rotate(length_a, index_a);
	cost_b = cost_rotate(length_b, index_b);
	if (index_a < length_a / 2 && index_b < length_b / 2)
	{
		if (cost_a > cost_b)
			return (cost_a + 1);
		else
			return (cost_b + 1);
	}
	if (index_a > length_a / 2 && index_b > length_b / 2)
	{
		if (cost_a > cost_b)
			return (cost_a + 1);
		else
			return (cost_b + 1);
	}
	return (cost_a + cost_b + 1);
}

void	get_cost(t_swap *stack_a, t_swap *stack_b)
{
	t_swap	*temp;
	int		index_a;
	int		index_b;
	int		length_a;
	int		length_b;

	temp = stack_a;
	length_a = stack_length(stack_a);
	length_b = stack_length(stack_b);
	while (temp)
	{
		index_a = stack_index(stack_a, temp->value);
		if (temp->value > stack_max(stack_b))
			index_b = stack_index(stack_b, stack_min(stack_b));
		else
			index_b = stack_index(stack_b, stack_next(stack_b, temp->value));
		temp->cost = cost(length_a, index_a, index_b, length_b) + 1;
		temp = temp->next;
	}
}

int	least_cost(t_swap *stack)
{
	int	min;
	int value;

	min = 0;
	while (stack)
	{
		if (min > stack->cost || min <= 0 )
		{
			min = stack->cost;
			value = stack->value;
		}
		stack = stack->next;
	}
	return (value);
}
