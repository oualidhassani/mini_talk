#include "minitalk.h"
#include "libft/libft.h"

void client_function(pid_t id, char *str)
{
	int i = 0;
	int j;

 while (str[i])
 {
	j = 7;
	
	while (j >= 0)
	{
		if(str[i] >> j & 1)
		{
			kill(id, SIGUSR1);
		}
		else
			kill(id, SIGUSR2);
		usleep(400);
		j--;
	}
	i++;
 }
}
int main(int ac, char **av)
{
	if (ac != 3)
		return (-1);
	int server_pid = ft_atoi(av[1]);
	char *str = ft_strdup(av[2]);
	if(!str)
		free(str);
	client_function(server_pid, str);
	client_function(server_pid, "\n");
}