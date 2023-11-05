/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:00:24 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 13:14:59 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_both(t_swap **stack_a, t_swap **stack_b, int times)
{
	while (times-- > 0)
		rr(*stack_a, *stack_b);
}

static void	rr_both(t_swap **stack_a, t_swap **stack_b, int times)
{
	while (times-- > 0)
		rrr(*stack_a, *stack_b);
}

static void	execute(t_swap **stack_a, t_swap **stack_b, int a, int b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(*stack_a);
	length_b = stack_length(*stack_b);
	if (a < length_a / 2)
	{
		while (a-- > 0)
			ra(*stack_a);
	}
	else
		while ((length_a - a++) > 0 && stack_length(*stack_a) > 1)
			rra(*stack_a);
	if (b < length_b / 2)
	{
		while (b-- > 0)
			rb(*stack_b);
	}
	else
		while ((length_b - b++) > 0 && stack_length(*stack_b) > 1)
			rrb(*stack_b);
}

static void	execute_both(t_swap **stack_a, t_swap **stack_b, int a, int b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(*stack_a);
	length_b = stack_length(*stack_b);
	if (a <= length_a / 2 && b <= length_b / 2)
	{
		if (a > b)
			r_both (stack_a, stack_b, b);
		else
			r_both (stack_a, stack_b, a);
	}
	else if (a >= length_a / 2 && b >= length_b / 2)
	{
		if (a > b)
			rr_both (stack_a, stack_b, length_b - b);
		else
			rr_both (stack_a, stack_b, length_a - a);
	}
}

void	send_object(t_swap **stack_a, t_swap **stack_b, int value)
{
	int	index_a;
	int	index_b;

	index_a = stack_index(*stack_a, value);
	if (value > stack_max(*stack_b))
		index_b = stack_index(*stack_b, stack_max(*stack_b));
	else
		index_b = stack_index(*stack_b, stack_next(*stack_b, value));
	if (index_a && index_b)
		execute_both(stack_a, stack_b, index_a, index_b);
	index_a = stack_index(*stack_a, value);
	if (value < stack_min(*stack_b))
		index_b = stack_index(*stack_b, stack_max(*stack_b));
	else
		index_b = stack_index(*stack_b, stack_next(*stack_b, value));
	execute(stack_a, stack_b, index_a, index_b);
}
