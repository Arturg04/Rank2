/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:07 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 21:31:29 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_swap *stack_a)
{
	int	length;

	length = stack_length(stack_a);
	while (!check_sorted(stack_a))
	{
		if (length <= 3)
			sort_3(&stack_a);
		else
			sort(&stack_a);
	}
	print_stacks(stack_a, NULL);
}

int	main(int ac, char **av)
{
	t_swap	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = (t_swap *)malloc(sizeof(t_swap));
	if (!stack_a)
		return (0);
	stack_a->next = NULL;
	if (ac > 2)
		check_params(ac, av, stack_a);
	else
		check_parameter(av[1], stack_a);
	push_swap(stack_a);
	free_stack(stack_a);
	return (1);
}
