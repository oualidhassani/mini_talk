#include "libft/libft.h"
#include "minitalk.h"

static int	is_string_digit(char *str)
{
	int	i;

	i = 0;
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
	int server_pid = ft_atoi(av[1]);
	char *str = ft_strdup(av[2]);
	if (is_string_digit(av[1]) == 0)
	 	return (-1);
	if (ac != 3)
		return (-1);
	if (!str)
		free(str);
	client_function(server_pid, str);
	// client_function(server_pid, "\n");
}