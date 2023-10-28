/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:55:42 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/28 01:14:01 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int sig)
{
	(void)sig;
	write(1, "Message sent successfully!\n", 27);
	exit(1);
}

void	ft_send(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
	usleep(50);
}

int	main(int ac, char **av)
{
	static int	pid;

	signal(SIGUSR1, signal_handler);
	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	while (*av[2])
		ft_send(pid, *av[2]++);
	ft_send(pid, *av[2]);
	while (1)
		pause();
	return (1);
}
