/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:33:38 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/24 10:11:11 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	ft_send_bit(int pid, int sig)
{
	if (sig == 1)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
		exit(1);
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
		usleep(50);
		i--;
	}
}

void	ft_send_string(int pid, char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0');
}

void	handler_client(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("the message was received\n");
		exit(1);
	}
	
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (-1);
	if (ft_is_string_digit(av[1]) == 0)
		return (-1);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, handler_client);
	signal(SIGUSR2, handler_client);
	ft_send_string(pid, av[2]);
	while (1)
	{
		pause();
	}
}
