#include "minitalkbonus.h"

static int	is_string_digit(char *str)
{
	int	i;

	i = 0;
	if(str[0] == 0)
		return(0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
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
	if(str[i] == '\0')
	{
		exit(EXIT_SUCCESS);
	}
}
void	handler_client(int sig)
{
	if (sig == SIGUSR1)
	 ft_printf("the message was received\n");
	if (sig == SIGUSR2)
		exit(0);
}
int	main(int ac, char **av)
{
	pid_t pid;
	if (ac != 3)
		return (-1);
	if(is_string_digit(av[1]) ==  0)
		return(-1);

	pid = ft_atoi(av[1]);
	signal(SIGUSR1, handler_client);
	signal(SIGUSR2, handler_client);

	client_function(pid, av[2]);
	while (1)
	{
		pause();
	}
}