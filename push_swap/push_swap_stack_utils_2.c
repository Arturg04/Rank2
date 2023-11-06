/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:24:45 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:59:19 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_b(t_swap *stack_b, int value)
{
	int		i;
	t_swap	*tmp;

	i = 1;
	if (value > stack_b->value && value < stack_last(stack_b)->value)
		i = 0;
	else if (value > stack_max(stack_b) || value < stack_min(stack_b))
		i = stack_index(stack_b, stack_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < value || tmp->value > value)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	next_a(t_swap *stack_a, int value)
{
	int		i;
	t_swap	*tmp;

	i = 1;
	if (value < stack_a->value && value > stack_last(stack_a)->value)
		i = 0;
	else if (value > stack_max(stack_a) || value < stack_min(stack_a))
		i = stack_index(stack_a, stack_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > value || tmp->value < value)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
