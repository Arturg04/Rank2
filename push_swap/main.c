/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:17:25 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 22:14:11 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*_stack_a;
	t_push_swap	*_stack_b;

	if (ac < 2)
		return (0);
	_stack_a = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!_stack_a)
		return (0);
	_stack_a->next = NULL;
	if (ac > 2)
		check_params(ac, av, _stack_a);
	else
		check_parameter(av[1], _stack_a);
	_stack_b = NULL;
	push_swap(_stack_a, _stack_b, ac - 1);
	//print_stacks(_stack_a, _stack_b);
	free_stack(_stack_a);
	free_stack(_stack_b);
	return (1);
}
