#include "./libft/libft.h"
#include "./printf/ft_printf.h"


int main(int argc, char **argv)
{
	pid_t			pid = atoi(argv[1]);
	size_t			a = ft_strlen(argv[2]);
	size_t 			tmp;
	size_t 			send;
	int				limit;
	int				ret;

	limit = 64;
	ret = -10;
	while (limit)
	{
		tmp = a << (limit - 1);
		send = tmp >> 63;
		ft_printf("%d\n", send);
		if (send == 0)
			ret = kill(pid, SIGUSR1);
		else if (send == 1)
			ret = kill(pid, SIGUSR2);
		else
			return (ft_printf("Error in conversion!"), FAILURE);
		if (ret < 0)
			return (ft_printf("%d\n%d\n", limit, ret), ft_printf("Error in sending signal!"), FAILURE);
		usleep(3);
		limit--;
	}
	return (ft_printf("Byte succesfully!"), SUCCESS);
}
