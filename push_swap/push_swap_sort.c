/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:39:47 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:16:25 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_swap **stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (!(i < j && j < k))
	{
		i = (*stack)->value;
		j = (*stack)->next->value;
		k = (*stack)->next->next->value;
		if ((k < i && i < j) || (i > j && j > k))
			rra(*stack);
		else if ((j < k && k < i))
			ra(*stack);
		else if ((j < i && i < k) || (k < i && i < j) || (i < k && k < j))
			sa(*stack);
	}
}

void	sort_until_3(t_swap **stack_a, t_swap **stack_b)
{
	int		i;
	t_swap	*tmp;

	while (stack_length(*stack_a) > 3 && !check_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->value))
				i = apply_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->value))
				i = apply_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->value))
				i = apply_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->value))
				i = apply_rrarb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_swap	*sort_b(t_swap **stack_a)
{
	t_swap	*stack_b;

	stack_b = NULL;
	if (stack_length(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (stack_length(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (stack_length(*stack_a) > 3 && !check_sorted(*stack_a))
		sort_until_3(stack_a, &stack_b);
	if (!check_sorted(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

t_swap	**sort_a(t_swap **stack_a, t_swap **stack_b)
{
	int		i;
	t_swap	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rrarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->value))
				i = apply_rrarb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort(t_swap **stack_a)
{
	t_swap	*stack_b;
	int		i;

	stack_b = NULL;
	if (stack_length(*stack_a) == 2)
		sa(*stack_a);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = stack_index(*stack_a, stack_min(*stack_a));
		if (i < stack_length(*stack_a) - i)
		{
			while ((*stack_a)->value != stack_min(*stack_a))
				ra(*stack_a);
		}
		else
		{
			while ((*stack_a)->value != stack_min(*stack_a))
				rra(*stack_a);
		}
	}
}
