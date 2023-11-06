/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:55:11 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_error(t_swap *stack)
{
	free_stack(stack);
	write(1, "Error\n", 6);
	exit(0);
}

void	free_stack(t_swap *stack)
{
	if (!stack)
		return ;
	if (stack->next)
		free_stack(stack->next);
	if (stack)
		free(stack);
}
