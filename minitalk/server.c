/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:56:01 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/26 00:28:51 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int bit)
{
	if (bit == SIGINT)
	{
		write(1, "\nServer Closed!\n", 16);
		exit(EXIT_SUCCESS);
	}
	if (bit == SIGUSR1)
	{
		write(1, "0", 1);
	}
	if (bit == SIGUSR2)
	{
		write(1, "1", 1);
	}
	signal(bit, signal_handler);
}

int	main(void)
{
	pid_t				pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, signal_handler);

	pid = getpid();
	write(1, "Server PID: ", ft_strlen("Server PID: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}