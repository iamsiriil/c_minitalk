/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 07:14:38 by toantune          #+#    #+#             */
/*   Updated: 2024/04/27 11:23:03 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("The message was recieved.\n");
		exit(EXIT_SUCCESS);
	}
}

static void	send_signal(pid_t pid, char bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Failed to send SIGUSR1 to './server'\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Failed to send SIGUSR2 to './server'\n");
			exit(EXIT_FAILURE);
		}
	}
	usleep(300);
}

static void	send_char(pid_t pid, char *message)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			bit = (message[i] >> j) & 1;
			send_signal(pid, bit);
			j--;
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		bit = ('\0' >> j) & 1;
		send_signal(pid, bit);
		j--;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Failed to recieve SIGUSR1 from './server'\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_char(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
