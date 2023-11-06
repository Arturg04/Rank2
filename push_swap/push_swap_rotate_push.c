/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:05:30 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 22:03:07 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rarb(t_swap **a, t_swap **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && next_b(*b, c) > 0)
			rr(*a, *b);
		while ((*a)->value != c)
			ra(*a);
		while (next_b(*b, c) > 0)
			rb(*b);
		pb(a, b);
	}
	else
	{
		while ((*b)->value != c && next_a(*a, c) > 0)
			rr(*a, *b);
		while ((*b)->value != c)
			rb(*b);
		while (next_a(*a, c) > 0)
			ra(*a);
		pa(a, b);
	}
	return (-1);
}

int	apply_rrarrb(t_swap **a, t_swap **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && next_b(*b, c) > 0)
			rrr(*a, *b);
		while ((*a)->value != c)
			rra(*a);
		while (next_b(*b, c) > 0)
			rrb(*b);
		pb(a, b);
	}
	else
	{
		while ((*b)->value != c && next_a(*a, c) > 0)
			rrr(*a, *b);
		while ((*b)->value != c)
			rrb(*b);
		while (next_a(*a, c) > 0)
			rra(*a);
		pa(a, b);
	}
	return (-1);
}

int	apply_rrarb(t_swap **a, t_swap **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			rra(*a);
		while (next_b(*b, c) > 0)
			rb(*b);
		pb(a, b);
	}
	else
	{
		while (next_a(*a, c) > 0)
			rra(*a);
		while ((*b)->value != c)
			rb(*b);
		pa(a, b);
	}
	return (-1);
}

int	apply_rarrb(t_swap **a, t_swap **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ra(*a);
		while (next_b(*b, c) > 0)
			rrb(*b);
		pb(a, b);
	}
	else
	{
		while (next_a(*a, c) > 0)
			ra(*a);
		while ((*b)->value != c)
			rrb(*b);
		pa(a, b);
	}
	return (-1);
}
