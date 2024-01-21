#include "minitalkbonus.h"

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
void handler_client(int sig, siginfo_t *info, void *walo)
{
	(void)walo; 
    static pid_t id = info->si_pid;

    if(sig == SIGUSR1)
        client_function(id, NULL);
	kill(id, SIGUSR1);
	if(sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}
int main ()
{
    struct sigaction sa;

    sa.sa_sigaction = handler_client;
    sa.sa_flags = SA_SIGINFO;

    if(sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        return(-1);
    
    
}