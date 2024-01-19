#include "minitalkbonus.h"

// int client = 0;

// static int	is_string_digit(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
// void	client_function(pid_t id, char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 7;
// 		while (j >= 0)
// 		{
// 			if (str[i] >> j & 1)
// 			{
// 				kill(id, SIGUSR1);
// 			}
// 			else
// 				kill(id, SIGUSR2);
// 			usleep(50);
// 			j--;
// 		}
// 		i++;
// 	}
// }
void handlemessage2(int sig)
{
    client = 0;
    if (sig == SIGUSR1)
        printf("client receive a message from the server\n");
    // else if (sig == SIGUSR2)
    //     exit(0);
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    // char *str = ft_strdup(av[2]);
    // int server_pid = ft_atoi(av[1]);

    // if(is_string_digit(av[1]) == 0)
    //     printf("wrong id\n");
    //     //return(-1);
    // if(!str)
    //     free(str);
    // if (ac != 3)
    // {
    //     free(str);
    //     ft_printf("ERROR\n");
    //     exit(1);
    // }

    struct sigaction sa;

    sa.sa_handler = &handlemessage2;
    sigemptyset(&sa.sa_mask);

    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_printf("ERROR\n");
    

    ft_printf("client sendng a message to the server\n");

    sleep(2);
}