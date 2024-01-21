#include "minitalkbonus.h"

    static char c; 
    static int bit_count;

void handler_signal(int sig, siginfo_t *siginfo, void* walo)
{
    (void)walo;
    pid_t client;

    client = siginfo->si_pid;

    if (sig == SIGUSR1)
    {
        bit_count++;
        c = c << 1 | 1;
        kill(client, SIGUSR1);
    }

    if(sig == SIGUSR2)
    {
        c = c << 1;
        bit_count++;
        kill(client, SIGUSR2);
    }

    if(bit_count == 8)
    {
        ft_printf("%c", c);
        c = 0;
        bit_count = 0;
    }
}
int main ()
{
    struct sigaction sa;

    sa.sa_sigaction = handler_signal;
    sa.sa_flags = SA_SIGINFO;
    pid_t server_pid = getpid();

    ft_printf("%d\n", server_pid);


    if(sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
        return(-1);
    
    while (1)
    {
        pause();

    }
    return(0);
}