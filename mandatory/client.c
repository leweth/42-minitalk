/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:00:38 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 16:23:43 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		len;
	int		err;

	err = SUCCESS;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments! \
You must include the server's pid and the string to send.");
		return (FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid process ID!"), FAILURE);
	len = ft_strlen(argv[2]);
	err = send_data(&len, sizeof(size_t), pid);
	if (err)
		return (FAILURE);
	send_data(argv[2], len, pid);
	if (err)
		return (FAILURE);
	return (SUCCESS);
}
