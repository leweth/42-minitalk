/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:28:28 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/10 15:28:50 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putaddress(va_list args)
{
	uintptr_t	num;

	num = va_arg(args, uintptr_t);
	return (write(1, "0x", 2) + ft_puthexa(num, "0123456789abcdef"));
}
