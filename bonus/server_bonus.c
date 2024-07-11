/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:53:55 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 12:26:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft_bonus.h"

t_data	g_data;

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

void	end_of_receiving(void)
{
	if ((g_data.received_bits >= 65) 
		&& (g_data.received_bits == 8 * ((size_t)g_data.len + 8)))
	{
		ft_printf("%s", g_data.string);
		if (kill(g_data.c_pid, SIGUSR1) < 0)
			exit(FAILURE);
		ft_clean(&g_data);
	}
}

void	signal_handler(int sigint, siginfo_t *sig_info, void *param)
{
	(void) param;
	if (!g_data.received_bits)
		g_data.c_pid = sig_info->si_pid;
	if (g_data.c_pid != sig_info->si_pid)
	{
		ft_clean(&g_data);
		g_data.c_pid = sig_info->si_pid;
	}
	g_data.received_bits++;
	if (g_data.received_bits <= 64)
		receive_byte(sigint, &g_data.len);
	else if (g_data.received_bits > 64)
	{
		if (g_data.len > 0)
		{
			set_up_string(&g_data);
			receive_byte(sigint, g_data.string);
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;
	int					ret;

	ret = 0;
	pid = getpid();
	ft_printf("Current process's pid is: %d\n", pid);
	act.sa_sigaction = signal_handler;
	act.sa_flags = SA_SIGINFO;
	initialize_global_var(&g_data);
	ret = sigaction(SIGUSR1, &act, NULL);
	ret = sigaction(SIGUSR2, &act, NULL);
	if (ret < 0)
		return (ft_printf("Error receiving signal!"), FAILURE);
	while (true)
		pause();
	return (SUCCESS);
}
