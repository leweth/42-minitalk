/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:12:28 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 12:26:59 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	initialize_global_var(t_data *g_data)
{
	g_data->string = NULL;
	g_data->len = 0;
	g_data->received_bits = 0;
	g_data->offset = 0;
	g_data->c_pid = 0;
	g_data->byte_pointer = 0;
}

void	ft_clean(t_data *g_data)
{
	free(g_data->string);
	initialize_global_var(g_data);
}

void	set_up_string(t_data *g_data)
{
	if (g_data->received_bits == 65) 
	{
		g_data->byte_pointer = 0;
		g_data->string = ft_calloc(g_data->len + 1, 1);
		if (!g_data->string)
			exit(FAILURE);
	}
}
