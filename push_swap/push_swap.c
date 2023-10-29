/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:07 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:32:09 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_push_swap *stack_a, t_push_swap *stack_b, int total)
{
	while (!check_solution(stack_a, stack_b))
	{
		print_stacks(stack_a, stack_b);
		sort(stack_a, stack_b, total);
		select_move(stack_a, stack_b, get_cost(stack_a, stack_b));

		if (total == 3)
			sort_3(stack_a);
		else if (!least_cost(get_cost(stack_a, stack_b)))
			break ;
		else
		{

		}
	}
	return ;
}

void	select_move(t_push_swap *stack_a, t_push_swap *stack_b, t_cost cost)
{
	int	temp;

	temp = least_cost(cost);
	if (temp == cost.sa && temp == cost.sb)
		return (ss(stack_a, stack_b));
	if (temp == cost.sa)
		return (sa(stack_a));
	if (temp == cost.sb)
		return (sb(stack_b));
	if (temp == cost.pa)
		return (pa(&stack_b, &stack_a));
	if (temp == cost.pb)
		return (pb(&stack_a, &stack_b));
	if (temp == cost.ra && temp == cost.rb)
		return (rr(stack_a, stack_b));
	if (temp == cost.ra)
		return (ra(stack_a));
	if (temp == cost.rb)
		return (rb(stack_b));
	if (temp == cost.rra && temp == cost.rrb)
		return (rrr(stack_a, stack_b));
	if (temp == cost.rra)
		return (rra(stack_a));
	if (temp == cost.rrb)
		return (rrb(stack_b));
}
