#include "minitalkbonus.h"

int client = 0;

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
void handlemessage2(int sig)
{
    client = 0;
    if (sig == SIGUSR1)
        printf("wsal");
    else if (sig == SIGUSR2)
        exit(0);
}

int main(int ac, char **av)
{
    char *str = ft_strdup(av[2]);
    int server_pid = ft_atoi(av[1]);

    if(is_string_digit(av[1]) == 0)
        printf("wrong id\n");
        //return(-1);
    if(!str)
        free(str);
    if (ac != 3)
    {
        free(str);
        ft_printf("ERROR\n");
        exit(1);
    }
    signal(SIGUSR1, handlemessage2);
    signal(SIGUSR2, handlemessage2);
    ft_printf("sending a message to the server\n");
    client_function(server_pid, str);
    client_function(server_pid, "\n");
    while(1)
    {
        if(client != 0)
        {
            ft_printf("received a signal from the server\n");

            client = 0;
            break;
        }
            sleep(1);
    }
    return(0);
}