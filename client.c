#include "libft/libft.h"
#include "minitalk.h"

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
}
int	main(int ac, char **av)
{
	if (ac != 3)
		return (-1);
	pid_t server_pid;
	if (is_string_digit(av[1]) == 0)
	 	return (-1);
	server_pid = ft_atoi(av[1]);
	client_function(server_pid, av[2]);
	
	return(0);
}