/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:56:21 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/11 11:56:22 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	block;

	block = size * count;
	if (count && block / count < size)
		return (NULL);
	ptr = malloc(block);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, block);
	return (ptr);
}
