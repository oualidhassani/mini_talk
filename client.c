/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:00:54 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:41 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_function(pid_t id, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] >> j & 1)
			{
				kill(id, SIGUSR1);
			}
			else
				kill(id, SIGUSR2);
			usleep(50);
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
		return (-1);
	if (ft_is_string_digit(av[1]) == 0)
		return (-1);
	server_pid = ft_atoi(av[1]);
	client_function(server_pid, av[2]);
	return (0);
}
