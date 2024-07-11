/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:57:12 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 12:08:14 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../printf/ft_printf.h"
# include <stdbool.h>

# define SUCCESS 0
# define FAILURE -1

# define OVERFLOW -1
# define UNDERFLOW 0

typedef struct s_data {
	unsigned char	*string;
	int				len;
	size_t			received_bits;
	size_t			offset;
	size_t			byte_pointer;
	pid_t			c_pid;
}	t_data;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		send_data(void *ptr, size_t limit, pid_t pid);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	initialize_global_var(t_data *g_data);
void	ft_clean(t_data *g_data);

#endif