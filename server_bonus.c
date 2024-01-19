#include "minitalkbonus.h"

int server = 0;

void handlemessage(int sig)
   {
        if(sig == SIGUSR1)
            ft_printf("the server received the message from the client\n");
   }
// void	handle_signal(int signal_msg)
// {
// 	static char	c;
// 	static char	bit_counter;

// 	if (signal_msg == SIGUSR1)
// 	{
// 		bit_counter++;
// 		c = c << 1 | 1;
// 	}
// 	else if (signal_msg == SIGUSR2)
// 	{
// 		c = c << 1;
// 		bit_counter++;
// 	}
// 	if (bit_counter == 8)
// 	{
// 		ft_printf("%c", c);
//         if (c == '\0')
//             handlemessage(signal_msg);
// 		c = 0;
// 		bit_counter = 0;
// 	}
// }

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    struct sigaction sa;

    sa.sa_handler = &handlemessage;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        ft_printf("ERROR\n");

    while(1)
    {
        ft_printf("server is waiting\n");
        sleep(1);

        ft_printf("server sending a signal to the server\n");

        kill(getpid(), SIGUSR1);
        // pause();
        
    }
}