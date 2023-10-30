/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:07 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/30 19:24:41 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_push_swap *stack_a, t_push_swap *stack_b)
{
	while (!check_solution(stack_a, stack_b))
	{
		if (stack_length(stack_a) == 3)
			sort_3(stack_a);
	}
	return ;
}
