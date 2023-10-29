/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:24:45 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:11:29 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_push_swap *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	return (++count + ft_lstsize(stack->next));
}

int	stack_min(t_push_swap *stack)
{
	int min;

	if (!stack)
		return (0);
	min = stack_min(stack->next);
	if (min > stack->value)
		return (stack->value);
	return (min);
}

int	stack_max(t_push_swap *stack)
{
	int max;

	if (!stack)
		return (0);
	max = stack_max(stack->next);
	if (max < stack->value)
		return (stack->value);
	return (max);
}
