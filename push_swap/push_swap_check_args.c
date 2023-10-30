/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:39:03 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/29 22:13:02 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num(char *num)
{
	if (*num == '-')
		num++;
	while (*num)
		if (!ft_isdigit(*num++))
			return (0);
	return (1);
}

static void	check_repeat(t_push_swap *stack)
{
	t_push_swap		*temp;
	t_push_swap		*check;

	check = stack;
	while (check->next)
	{
		temp = check->next;
		while (temp->next)
		{
			if (check->value == temp->value)
				call_error(stack);
			temp = temp->next;
		}
		check = check->next;
	}
}

void	check_params(int ac, char	**av, t_push_swap *stack)
{
	int				i;
	long long int	j;
	t_push_swap		*temp;

	i = 0;
	temp = stack;
	while (++i < ac)
	{
		if (!check_num(av[i]))
			call_error(stack);
		j = ft_atoi(av[i]);
		if (j < FT_INT_MIN || j > FT_INT_MAX)
			call_error(stack);
		temp->value = j;
		if (!(i + 1 < ac))
			break ;
		temp->next = malloc(sizeof(t_push_swap));
		if (!temp->next)
			call_error(stack);
		temp = temp->next;
		temp->next = NULL;
	}
	check_repeat(stack);
}

int	check_solution(t_push_swap *stack_a, t_push_swap *stack_b)
{
	if (stack_b || !stack_a)
		return (0);
	while (stack_a->next && stack_a)
	{
		if (stack_a->next->value < stack_a->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_order(t_push_swap *stack)
{
	int	temp;

	temp = stack->value;
	while (stack->next && stack)
	{
		if (stack->next->value < stack->value)
			break ;
		stack = stack->next;
	}
	stack = stack->next;
	if (!stack)
		return (1);
	while (stack->next && stack)
	{
		if (stack->next->value < stack->value)
			break ;
		stack = stack->next;
	}
	if (stack->value < temp && !stack->next)
		return (1);
	return (0);
}
