/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 20:26:48 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_error(t_push_swap *_stack)
{
	free_stack(_stack);
	write(1, "Error\n", 6);
	exit(0);
}
void	free_stack(t_push_swap *_stack)
{
	if (!_stack)
		return ;
	if (_stack->next)
		free_stack(_stack->next);
	if (_stack)
		free(_stack);
}

void	print_stacks(t_push_swap *_stack_a, t_push_swap *_stack_b)
{
	while (_stack_a || _stack_b)
	{
		if (_stack_a)
		{
			ft_putnbr_fd(_stack_a->value, 1);
			_stack_a = _stack_a->next;
		}
		else
			write(1, "     ", 5);
		write(1, "|", 1);
		if (_stack_b)
		{
			ft_putnbr_fd(_stack_b->value, 1);
			_stack_b = _stack_b->next;
		}
		else
			write(1, "     ", 5);
		write(1, "\n", 1);
	}
}
