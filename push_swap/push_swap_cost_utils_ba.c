/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost_utils_ba.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:59 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 22:03:27 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_a(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = next_a(a, c);
	if (i < stack_index(b, c))
		i = stack_index(b, c);
	return (i);
}

int	case_rrarrb_a(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (next_a(a, c))
		i = stack_length(a) - next_a(a, c);
	if ((i < (stack_length(b) - stack_index(b, c))) && stack_index(b, c))
		i = stack_length(b) - stack_index(b, c);
	return (i);
}

int	case_rarrb_a(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (stack_index(b, c))
		i = stack_length(b) - stack_index(b, c);
	i = next_a(a, c) + i;
	return (i);
}

int	case_rrarb_a(t_swap *a, t_swap *b, int c)
{
	int	i;

	i = 0;
	if (next_a(a, c))
		i = stack_length(a) - next_a(a, c);
	i = stack_index(b, c) + i;
	return (i);
}
