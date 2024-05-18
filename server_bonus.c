/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toantune <toantune@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 07:14:56 by toantune          #+#    #+#             */
/*   Updated: 2024/04/27 12:36:22 by toantune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_message = NULL;

static size_t	ft_strlen_ps(unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static unsigned char	*append_char(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*str;
	unsigned char	*ptr;
	unsigned char	*ptr_s1;

	ptr_s1 = s1;
	if (!s1)
	{
		str = malloc(sizeof(unsigned char) * 2);
		ft_strlcpy(str, s2, 2);
		return (str);
	}
	str = malloc(sizeof(char) * (ft_strlen_ps(s1) + ft_strlen_ps(s2) + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(ptr_s1);
	return (ptr);
}

static void	terminate_message(int sig, siginfo_t *info, unsigned char character)
{
	g_message = append_char(g_message, &character);
	ft_printf("%s\n", g_message);
	free(g_message);
	g_message = NULL;
	if (kill(info->si_pid, sig) == -1)
	{
		ft_printf("Failed to send SIGUSR1 to './client'\n");
		exit(EXIT_FAILURE);
	}
}

static void	signal_handler(int sig, siginfo_t *info, void *other)
{
	static unsigned char	character;
	static int				shift = 7;

	(void)other;
	if (sig == SIGUSR2)
		character |= (1 << shift);
	shift--;
	if (shift < 0)
	{
		if (character == '\0')
			terminate_message(sig, info, character);
		else
			g_message = append_char(g_message, &character);
		character = 0;
		shift = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Failed to recieve SIGUSR1 from './client'\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Failed to recieve SIGUSR2 from './client'\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
