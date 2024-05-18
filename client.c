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
	pid_t		pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <Message>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_char(pid, argv[2]);
	return (0);
}
