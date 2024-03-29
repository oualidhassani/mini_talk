/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:51:44 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/24 09:56:23 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal_msg)
{
	static char	c;
	static char	bit_counter;

	if (signal_msg == SIGUSR1)
	{
		bit_counter++;
		c = c << 1 | 1;
	}
	else if (signal_msg == SIGUSR2)
	{
		c = c << 1;
		bit_counter++;
	}
	if (bit_counter == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit_counter = 0;
	}
}

int	main(int ac, char **av)
{
	if (ac != 1)
		return (-1);
	(void)av;
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
}
