/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:34 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memmove() function copies n bytes from memory area src to memory area
	dest.  The memory areas may overlap: copying takes place as though the
	bytes in src are first copied into a temporary array that not overlap
	src or dest, and the bytes are then copied from the temporary array to dest.

RETURN VALUE
	The memmove() function returns a pointer to dest.
*/

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *) src;
	i = 0;
	if (dest > src)
		while (n--)
			aux_dest[n] = aux_src[n];
	else
	{
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	return (dest);
}
