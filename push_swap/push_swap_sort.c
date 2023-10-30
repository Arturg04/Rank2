/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:39:47 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/30 19:57:27 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_push_swap *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (!(i < j && j < k))
	{
		i = stack->value;
		j = stack->next->value;
		k = stack->next->next->value;
		if (k < i && i < j)
			rra(stack);
		else if ((j < k && k < i) || (i > j && j  > k))
			ra(stack);
		else if ((j < i && i < k) || (k < i && i < j) || (i < k && k < j))
			sa(stack);
	}
}

void	sort_5(t_push_swap *stack_a, t_push_swap *stack_b)
{
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	sort_3(stack_a);
	while (!check_solution(stack_a, stack_b))
	{
		if (stack_max(stack_a) < stack_b->value)
			rra(stack_a);
		else if (stack_a->value > stack_b->value)
			pa(&stack_a, &stack_b);
		else
			ra(stack_a);
	}
}
