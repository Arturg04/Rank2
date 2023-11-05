/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:24:45 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 03:49:12 by ade-pinh         ###   ########.fr       */
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
	if (!stack)
		return (0);
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
	if (!stack)
		return (0);
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
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == value)
			break ;
		stack = stack->next;
		index++;
	}
	return (index);
}

int	stack_next(t_swap *stack, int value)
{
	int	next;

	next = 0;
	if (!stack)
		return (0);
	if (value > stack_max(stack))
		return(stack_max(stack));
	while (stack)
	{
		if (!stack)
			break ;
		if ((next < stack->value && stack->value <= value) || (stack->value >= value && next > stack->value))
			next = stack->value;
		stack = stack->next;
	}
	return (next);
}
