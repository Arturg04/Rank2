/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:39:47 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 16:20:16 by ade-pinh         ###   ########.fr       */
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
			rotate_reverse(stack, 'a');
		else if ((j < k && k < i) || (i > j && j  > k))
			rotate(stack, 'a');
		else if ((j < i && i < k) || (k < i && i < j) || (i < k && k < j))
			swap(stack, 'a');
	}
}

void	sort(t_push_swap *stack_a, t_push_swap *stack_b, int total)
{
	divide_in_stacks(&stack_a, &stack_b, total / 2);
}

void	divide_in_stacks(t_push_swap **stack_a, t_push_swap **stack_b, int size)
{

}
