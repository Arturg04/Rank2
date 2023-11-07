/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:39:19 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/07 09:11:00 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ba(t_swap *a, t_swap *b)
{
	int		i;
	t_swap	*tmp;

	tmp = b;
	i = get_cost(b, a, b->value, &next_a);
	//i = count_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > get_cost(b, a, tmp->value, &next_a))
			i = get_cost(b, a, tmp->value, &next_a);
		// if (i > count_rarb_a(a, b, tmp->value))
		// 	i = count_rarb_a(a, b, tmp->value);
		// if (i > count_rrarrb_a(a, b, tmp->value))
		// 	i = count_rrarrb_a(a, b, tmp->value);
		// if (i > count_rarrb_a(a, b, tmp->value))
		// 	i = count_rarrb_a(a, b, tmp->value);
		// if (i > count_rrarb_a(a, b, tmp->value))
		// 	i = count_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_swap *a, t_swap *b)
{
	int		i;
	t_swap	*tmp;

	tmp = a;
	i = get_cost(a, b, a->value, &next_b);
	//i = count_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > get_cost(a, b, tmp->value, &next_b))
			i = get_cost(a, b, tmp->value, &next_b);
		// if (i > count_rarb(a, b, tmp->value))
		// 	i = count_rarb(a, b, tmp->value);
		// if (i > count_rrarrb(a, b, tmp->value))
		// 	i = count_rrarrb(a, b, tmp->value);
		// if (i > count_rarrb(a, b, tmp->value))
		// 	i = count_rarrb(a, b, tmp->value);
		// if (i > count_rrarb(a, b, tmp->value))
		// 	i = count_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}