/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:33:42 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/24 09:58:49 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	handler_signal(int sig, siginfo_t *siginfo, void *walo)
{
	static char	c;
	static int	bit_count;
	pid_t		client;

	(void)walo;
	client = siginfo->si_pid;
	if (sig == SIGUSR1)
	{
		bit_count++;
		c = c << 1 | 1;
	}
	else if (sig == SIGUSR2)
	{
		c = c << 1;
		bit_count++;
	}
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(client, SIGUSR1);
		c = 0;
		bit_count = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				server_pid;

	(void)av;
	if (ac != 1)
		return (-1);
	sa.sa_sigaction = handler_signal;
	sa.sa_flags = SA_SIGINFO;
	server_pid = getpid();
	ft_printf("%d\n", server_pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL)
		== -1)
		return (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
