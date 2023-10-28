/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:56:01 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/10/28 15:37:31 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	build_char(int signal, siginfo_t *info, void *content)
{
	static int		i;
	static wchar_t	c;

	(void)content;
	if (signal != SIGUSR1 && signal != SIGUSR2)
	{
		i = 0;
		c = 0;
		return ;
	}
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 32)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	signal_handler(int bit, siginfo_t *info, void *content)
{
	build_char(bit, info, content);
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	build_char(0, NULL, NULL);
	write(1, "Server PID: ", ft_strlen("Server PID: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
	return (EXIT_SUCCESS);
}
