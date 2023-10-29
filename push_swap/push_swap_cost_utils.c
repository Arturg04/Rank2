/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:10:38 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 02:29:54 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	get_cost(t_push_swap *stack_a, t_push_swap *stack_b)
{
	if (check_order(stack_a) && !stack_b)
		return (only_rotate(stack_a));
	return (inicialize_cost());
}

int	least_cost(t_cost cost)
{
	int	val;

	val = cost.sa;
	if ((cost.sb > 0 && cost.sb < val) || val == 0)
		val = cost.sb;
	if ((cost.pa > 0 && cost.pa < val) || val == 0)
		val = cost.pa;
	if ((cost.pb > 0 && cost.pb < val) || val == 0)
		val = cost.pb;
	if ((cost.ra > 0 && cost.ra < val) || val == 0)
		val = cost.ra;
	if ((cost.rb > 0 && cost.rb < val) || val == 0)
		val = cost.rb;
	if ((cost.rra > 0 && cost.rra < val) || val == 0)
		val = cost.rra;
	if ((cost.rrb > 0 && cost.rrb < val) || val == 0)
		val = cost.rrb;
	return (val);
}

t_cost inicialize_cost(void)
{
	t_cost init;

	init.sa = 0;
	init.sb = 0;
	init.pa = 0;
	init.pb = 0;
	init.ra = 0;
	init.rb = 0;
	init.rra = 0;
	init.rrb = 0;
	return (init);
}

