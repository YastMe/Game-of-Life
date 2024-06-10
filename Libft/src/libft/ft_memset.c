/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:45 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:03 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memset() function fills the first n bytes of the memory area pointed
	to by s with the constant byte c.

RETURN VALUE
    The memset() function returns a pointer to the memory area s.
*/

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (s);
}
