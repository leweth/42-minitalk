#include "./libft/libft.h"
#include "./printf/ft_printf.h"


int	main(int argc, char **argv)
{
	pid_t	pid;
	size_t	len;
	int		err;

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
	// ft_printf("--- %d ---\n", len);
	err = send_data(&len, sizeof(size_t), pid);
	if (err)
		return (ft_printf("Exit Failure."), FAILURE);
	send_data(argv[2], len, pid);
	if (err)
		return (ft_printf("Exit Failure."), FAILURE);
	return (SUCCESS);
}
