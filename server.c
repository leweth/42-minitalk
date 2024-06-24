#include "./libft/libft.h"

t_data	data;

void	initialize_global_var()
{
	data.string = NULL;
	data.received = false;
	data.len = 0;
	data.received_bits = 0;
	data.offset = 0;
	data.err = 0;
	data.c_pid = 0;
	data.byte_pointer = 0;
}
void	ft_clean()
{
	free(data.string);
	initialize_global_var();
}
void	receive_bit(int sigint, void *ptr)
{
	size_t			tmp;
	size_t			*p;

	p = (size_t *) ptr;
	tmp = 0;
	if (sigint == SIGUSR1)
		tmp = 0;
	else if (sigint == SIGUSR2)
		tmp = 1;
	*p += tmp << (data.received_bits - data.offset - 1);
}

void	signal_handler(int sigint, siginfo_t *sig_info, void *param)
{
	param = (void *) param;
	if (!data.received_bits)
		data.c_pid = sig_info->si_pid;
	if (data.c_pid != sig_info->si_pid)
	{
		ft_clean();
		data.c_pid = sig_info->si_pid;
	}
	data.received_bits++;
	if (data.received_bits <= 64 && !data.err)
		receive_bit(sigint, &data.len);
	else if (data.received_bits > 64)
	{
		if (data.received_bits == 65) 
		{
			data.offset = 64;
			data.string = ft_calloc(data.len + 1, 1);
			ft_printf("%d\n", data.len);
			if (!data.string)
			{
				data.err = 1;
				ft_clean();
			}
		}
		if (!data.err)
		{
			receive_bit(sigint, data.string + data.byte_pointer);
			if (data.received_bits % 8 == 0)
			{
				data.offset += 8;
				data.byte_pointer++;
			}
		}
	}
	if ((data.received_bits >= 65) && (data.received_bits == 8 * (data.len + 8)) && !data.err) // we this code, a problem would arise in thecase of anempty string, nothing will be reinitilized for the nextbatch of signals
	{	
		data.received = true;
		ft_printf("---%s---\n", data.string);
		ft_clean();
	}
}

/* int main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Current process's pid is: %d\n", pid);
	initialize_global_var();
	signal(SIGUSR1, signal_handler); // As long as there is this function here and the process is still runing then it is possible to  catch incoming signals?
	signal(SIGUSR2, signal_handler);
	while (True)
	{
		if (data.err)
			return (ft_printf("Error number %d was found.\n", data.err), FAILURE);
		if (data.received)
			break ;
	}
	ft_printf("---%s---\n", data.string); // he played a bit here
	ft_clean();
	return (SUCCESS);
} */

// What happens if we spcify SIG_DFL and there is no dfault action for the signal handler 
//(it is a default handler)
int	main()
{
	pid_t				pid;
	struct sigaction	act;
	int					ret = 0;

	pid = getpid();
	ft_printf("Current process's pid is: %d\n", pid);
	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	initialize_global_var();
	ret = sigaction(SIGUSR1, &act, NULL);
	ret = sigaction(SIGUSR2, &act, NULL);
	if (ret < 0)
		return (ft_printf("Error receiving signal!"), FAILURE);
	while (true)
	{
		if (data.err == 1)
			return (ft_printf("Error number %d was found.\n", data.err), FAILURE);
		pause();
	}
	return (SUCCESS);
}
