/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:55:42 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/26 00:14:13 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fr_send_bit(int pid, char c)
{

}

int	main(int ac, char **av)
{
	static int	pid;

	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	while (av[2] && *av[2])
	{

	}
	return (1);
}