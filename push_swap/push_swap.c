/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:28:07 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/05 03:35:31 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_swap *stack_a, t_swap *stack_b)
{
	int	length;

	length = stack_length(stack_a);
	while (!check_solution(stack_a, stack_b))
	{
		if (length <= 3)
			sort_3(&stack_a);
		// else if (length <= 5)
		// 	sort_5(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b);
		//print_stacks(stack_a, stack_b);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_swap	*stack_a;
	t_swap	*stack_b;

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
	stack_b = NULL;
	push_swap(stack_a, stack_b);
	//print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}
