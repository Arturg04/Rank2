/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:55:42 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/26 00:33:21 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, int i)
{
	if (i)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(100);
}

int	main(int ac, char **av)
{
	static int	pid;
	int			i;

	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	i = 2;
	while (av[i] && i < ac)
	{
		ft_send(pid, ft_atoi(av[i++]));
	}
	return (1);
}