#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include <stdbool.h>

int stop = false;

size_t	a; 

void	signalHandler(sigint)
{
	size_t			tmp;
	static size_t	bits_received;

	bits_received++;
	ft_printf("%d\n", bits_received);
	if (sigint == SIGUSR1)
		tmp = 0;
	else if (sigint == SIGUSR2)
		tmp = 1;
	tmp = tmp << (bits_received - 1);
	a += tmp;
	if (bits_received == 64)
		stop = true;
}

int main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Current process's pid is: %d\n", pid);
	a = 0;
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while (true)
	{
		if (stop)
			break ;
	}
	ft_printf("-------%d-------\n", a);
}
