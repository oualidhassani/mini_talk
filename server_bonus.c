#include "minitalkbonus.h"

int server = 0;

void handlemessage(int sig)
   {
        (void)sig;
        server = 1;
   }
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
        if (c == '\0')
            handlemessage(signal_msg);
		c = 0;
		bit_counter = 0;
	}
}

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
        return(-1);
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);   

    ft_printf("server waiting for the signal\n");

    while(1)
    {
        if (server != 0)
        {
            ft_printf("received a signal from the client\n");
                kill(getpid(), SIGUSR2);

            server = 0;
            
            sleep(1);
        }
    }
}