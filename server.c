#include "lib/libft/libft.h"

t_data	g_data;

void	initialize_global_var()
{
	g_data.string = NULL;
	g_data.len = 0;
	g_data.received_bits = 0;
	g_data.offset = 0;
	g_data.c_pid = 0;
	g_data.byte_pointer = 0;
}

void	ft_clean()
{
	free(g_data.string);
	initialize_global_var();
}
void	receive_bit(int sigint, void *ptr)
{
	unsigned char	tmp;
	unsigned char	*p;

	p = (unsigned char *) ptr;
	tmp = 0;
	if (sigint == SIGUSR1)
		tmp = 0;
	else if (sigint == SIGUSR2)
		tmp = 1;
	*p += tmp << (g_data.received_bits - g_data.offset - 1);
}

void	receive_byte(int sigint, void *ptr)
{
	receive_bit(sigint, ptr + g_data.byte_pointer);
	if (g_data.received_bits % 8 == 0)
	{
		g_data.offset += 8;
		g_data.byte_pointer++;
	}	
}

void	set_up_string()
{
	if (g_data.received_bits == 65) 
	{
		g_data.byte_pointer = 0;
		g_data.string = ft_calloc(g_data.len + 1, 1);
		if (!g_data.string)
			exit(FAILURE);
	}
}

void	signal_handler(int sigint, siginfo_t *sig_info, void *param)
{
	(void) param;
	if (!g_data.received_bits)
		g_data.c_pid = sig_info->si_pid;
	if (g_data.c_pid != sig_info->si_pid)
	{
		ft_clean();
		g_data.c_pid = sig_info->si_pid;
	}
	g_data.received_bits++;
	if (g_data.received_bits <= 64)
		receive_byte(sigint, &g_data.len);
	else if (g_data.received_bits > 64)
		if ( g_data.len > 0)
		{
			set_up_string();
			receive_byte(sigint, g_data.string);
		}
	if ((g_data.received_bits >= 65) && (g_data.received_bits == 8 * ((size_t)g_data.len + 8)))
	{	
		ft_printf("%s\n", g_data.string);
		if (kill(g_data.c_pid, SIGUSR1) < 0)
			exit(FAILURE);
		ft_clean();
	}
}

int	main()
{
	pid_t				pid;
	struct sigaction	act;
	int					ret;

	ret = 0;
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
		pause();
	return (SUCCESS);
}
