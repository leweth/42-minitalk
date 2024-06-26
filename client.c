#include "lib/libft/libft.h"

void	signal_handler(int sigint)
{
	if (sigint == SIGUSR1)
		ft_printf("Message Successfully received!\n");
	exit(SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		len;
	int		err;

	signal(SIGUSR1, signal_handler);
	err = SUCCESS;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments! You must include the server's pid and the string to send.");
		return (FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_printf("Invalid process ID!");
	len = ft_strlen(argv[2]);
	err = send_data(&len, sizeof(size_t), pid);
	if (err)
		return (ft_printf("Exit Failure."), FAILURE);
	send_data(argv[2], len, pid);
	if (err)
		return (ft_printf("Exit Failure."), FAILURE);
	while (true)
		pause();
	return (SUCCESS);
}
