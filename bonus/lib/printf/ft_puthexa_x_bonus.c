/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_x_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:10:39 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/10 15:28:58 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_puthexa_x(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_puthexa(num, "0123456789abcdef"));
}
