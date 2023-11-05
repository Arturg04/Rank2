/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:39:47 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 13:15:06 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_swap **stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (!(i < j && j < k))
	{
		i = (*stack)->value;
		j = (*stack)->next->value;
		k = (*stack)->next->next->value;
		if ((k < i && i < j) || (i > j && j > k))
			rra(*stack);
		else if ((j < k && k < i))
			ra(*stack);
		else if ((j < i && i < k) || (k < i && i < j) || (i < k && k < j))
			sa(*stack);
	}
}

void	sort_5(t_swap **stack_a, t_swap **stack_b)
{
	if ((*stack_a)->value == stack_max(*stack_a))
		ra(*stack_a);
	pb(stack_a, stack_b);
	if ((*stack_a)->value == stack_max(*stack_a))
		ra(*stack_a);
	if (stack_length(*stack_a) > 4)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	while (!check_solution(*stack_a, *stack_b))
	{
		if (!*stack_b)
		{
			if (stack_index(*stack_a, stack_min(*stack_a)) < stack_length(*stack_a) / 2)
				rra(*stack_a);
			else
				ra(*stack_a);
		}
		else if ((*stack_a)->value < (*stack_b)->value)
			pa(stack_a, stack_b);
		else
			rra(*stack_a);
	}
}

void	sort(t_swap **stack_a, t_swap **stack_b)
{
	int	length;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (*stack_a)
	{
		//print_stacks(*stack_a, *stack_b);
		get_cost(*stack_a, *stack_b);
		send_object(stack_a, stack_b, least_cost(*stack_a));
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
	length = stack_length(*stack_a);
	//print_stacks(*stack_a, *stack_b);
	while (!check_solution(*stack_a, *stack_b))
	{
		if (stack_index(*stack_a, stack_min(*stack_a)) < length / 2)
			ra(*stack_a);
		else
			rra(*stack_a);
	}
}
