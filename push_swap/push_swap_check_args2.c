/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_args2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:39:03 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/06 21:07:25 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num(char *num)
{
	if (*num == '-' && ft_isdigit(*(num + 1)))
		num++;
	while (*num)
		if (!ft_isdigit(*num++))
			return (0);
	return (1);
}

static void	check_repeat(t_swap *stack)
{
	t_swap		*temp;
	t_swap		*check;

	check = stack;
	while (check)
	{
		temp = check->next;
		while (temp)
		{
			if (check->value == temp->value)
				call_error(stack);
			temp = temp->next;
		}
		check = check->next;
	}
}

void	remove(t_swap *stack, char **split)
{
	int	i;

	i = -1;
	while (stack->next->next)
		stack = stack->next;
	free(stack->next);
	stack->next = NULL;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	check_parameter(char *str, t_swap *stack)
{
	int				i;
	long long int	j;
	char			**split;
	t_swap			*temp;

	i = -1;
	if (!*str)
		call_error(stack);
	split = ft_split(str, ' ');
	temp = stack;
	while (split[++i])
	{
		if (!check_num(split[i]))
			call_error(stack);
		j = ft_atoi(split[i]);
		if (j < FT_INT_MIN || j > FT_INT_MAX)
			call_error(stack);
		temp->value = j;
		temp->next = malloc(sizeof(t_swap));
		if (!temp->next)
			call_error(stack);
		temp = temp->next;
		temp->next = NULL;
	}
	remove(stack, split);
	check_repeat(stack);
}
