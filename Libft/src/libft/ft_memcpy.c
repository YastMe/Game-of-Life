/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:23 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:05 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memcpy() function copies n bytes from memory area src to memory area
	dest.  The memory areas must not overlap.  Use memmove(3) if the memory
	areas do overlap.

RETURN VALUE
	The memcpy() function returns a pointer to dest.
*/

#include "../../include/libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;

	if (!dest && !src)
		return (0);
	if ((dest == src) || n == 0)
		return (dest);
	aux_dest = (unsigned char *)dest;
	aux_src = (const unsigned char *)src;
	while (n--)
		aux_dest[n] = aux_src[n];
	return (dest);
}
