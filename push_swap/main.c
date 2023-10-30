/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:17:25 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/30 19:44:25 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*stack_a;
	t_push_swap	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!stack_a)
		return (0);
	stack_a->next = NULL;
	if (ac > 2)
		check_params(ac, av, stack_a);
	else
		check_parameter(av[1], stack_a);
	stack_b = NULL;
	if (ac - 1 == 3 && !check_solution(stack_a, stack_b))
		sort_3(stack_a);
	else if (ac - 1 == 5 && !check_solution(stack_a, stack_b))
		sort_5(stack_a, stack_b);
	else
		print_stacks(stack_a, stack_b);
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}
