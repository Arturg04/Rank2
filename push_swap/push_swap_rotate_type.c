/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:39:19 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:28:52 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ba(t_swap *a, t_swap *b)
{
	int		i;
	t_swap	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->value))
			i = case_rarb_a(a, b, tmp->value);
		if (i > case_rrarrb_a(a, b, tmp->value))
			i = case_rrarrb_a(a, b, tmp->value);
		if (i > case_rarrb_a(a, b, tmp->value))
			i = case_rarrb_a(a, b, tmp->value);
		if (i > case_rrarb_a(a, b, tmp->value))
			i = case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_swap *a, t_swap *b)
{
	int		i;
	t_swap	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->value))
			i = case_rarb(a, b, tmp->value);
		if (i > case_rrarrb(a, b, tmp->value))
			i = case_rrarrb(a, b, tmp->value);
		if (i > case_rarrb(a, b, tmp->value))
			i = case_rarrb(a, b, tmp->value);
		if (i > case_rrarb(a, b, tmp->value))
			i = case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}