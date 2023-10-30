/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/30 19:21:54 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_error(t_push_swap *stack)
{
	free_stack(stack);
	write(1, "Error\n", 6);
	exit(0);
}
void	free_stack(t_push_swap *stack)
{
	if (!stack)
		return ;
	if (stack->next)
		free_stack(stack->next);
	if (stack)
		free(stack);
}

void	print_stacks(t_push_swap *stack_a, t_push_swap *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_putnbr_fd(stack_a->value, 1);
			stack_a = stack_a->next;
		}
		else
			write(1, "     ", 5);
		write(1, "|", 1);
		if (stack_b)
		{
			ft_putnbr_fd(stack_b->value, 1);
			stack_b = stack_b->next;
		}
		else
			write(1, "     ", 5);
		write(1, "\n", 1);
	}
}
