/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:56:01 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/28 15:37:33 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	build_char(int signal)
{
	static int	i;
	static char	c;

	if (signal != SIGUSR1 && signal != SIGUSR2)
	{
		i = 0;
		c = 0;
		return ;
	}
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	signal_handler(int bit)
{
	build_char(bit);
	signal(bit, signal_handler);
}

int	main(void)
{
	int					pid;

	pid = getpid();
	build_char(0);
	write(1, "Server PID: ", ft_strlen("Server PID: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
	}
	return (EXIT_SUCCESS);
}
