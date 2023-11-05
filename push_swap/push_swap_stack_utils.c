/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:24:45 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:28:02 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_swap *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	stack_min(t_swap *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_swap *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	stack_index(t_swap *stack, int value)
{
	int		index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			break ;
		stack = stack->next;
		index++;
	}
	return (index);
}

t_swap	*stack_last(t_swap *stack)
{
	if (!stack || !stack->next)
		return (stack);
	return (stack_last(stack->next));
}
