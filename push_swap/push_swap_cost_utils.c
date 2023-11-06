/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/06 22:40:09 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rarb(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = next_b(b, c);
	if (i < stack_index(a, c))
		i = stack_index(a, c);
	return (i);
}

int	count_rrarrb(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (next_b(b, c))
		i = stack_length(b) - next_b(b, c);
	if ((i < (stack_length(a) - stack_index(a, c))) && stack_index(a, c))
		i = stack_length(a) - stack_index(a, c);
	return (i);
}

int	count_rrarb(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (stack_index(a, c))
		i = stack_length(a) - stack_index(a, c);
	i = next_b(b, c) + i;
	return (i);
}

int	count_rarrb(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (next_b(b, c))
		i = stack_length(b) - next_b(b, c);
	i = stack_index(a, c) + i;
	return (i);
}
