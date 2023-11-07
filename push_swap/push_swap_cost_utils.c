/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/07 09:10:58 by ade-pinh         ###   ########.fr       */
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

// int	get_cost(t_swap *src, t_swap *dst, int i, int (*n)(t_swap *d, int i))
// {
// 	int	cost_s;
// 	int	cost_d;

// 	cost_s = cost(src, i);
// 	cost_d = cost(dst, n(dst, i));
// 	if (cost_s < 0)
// 		cost_s = -cost_s;
// 	if (cost_d < 0)
// 		cost_d = -cost_d;
// 	return (cost_d + cost_s + 1);
// }

// int	cost(t_swap *stack, int i)
// {
// 	int	length;
// 	int	index;

// 	length = stack_length(stack);
// 	index = stack_index(stack, i);
// 	if (index < ((length + 1) / 2))
// 		return (index);
// 	return (index - length);
// }