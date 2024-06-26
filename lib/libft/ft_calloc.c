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
