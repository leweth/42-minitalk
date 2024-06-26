#include "libft.h"

int	send_byte(unsigned char *ptr, pid_t pid)
{
	unsigned char 	tmp;
	unsigned char 	send;
	int				limit;
	int				ret;

	limit = 8;
	ret = FAILURE;
	while (limit)
	{
		tmp = *ptr << (limit - 1);
		send = tmp >> 7;
		if (send == 0)
			ret = kill(pid, SIGUSR1);
		else if (send == 1)
			ret = kill(pid, SIGUSR2);
		else
			return (ft_printf("Error in conversion!\n"), FAILURE);
		if (ret < 0)
			return (ft_printf("%d\n%d\n", limit, ret), ft_printf("Error in sending signal!\n"), FAILURE);
		usleep(200);
		limit--;
	}
	return (SUCCESS);
}


int	send_data(void *ptr, size_t limit, pid_t pid)
{
	size_t			i;
	int				err;
	unsigned char	*p;

	p = (unsigned char *) ptr;
	err = SUCCESS;
	i = 0;
	while (i < limit)
	{
		err = send_byte(ptr + i, pid);
		if (err)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
