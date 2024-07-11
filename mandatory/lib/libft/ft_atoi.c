/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:55:09 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 11:55:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	conv;
	int					minus;

	i = 0;
	conv = 0;
	minus = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		minus = (str[i++] == '-') * (-1);
	while (ft_isdigit(str[i]))
	{
		conv = (conv * 10) + str[i++] - '0';
		if (conv > LLONG_MAX && minus == 1)
			return (OVERFLOW);
		if (conv > LLONG_MAX && minus == -1)
			return (UNDERFLOW);
	}
	return (minus * conv);
}
