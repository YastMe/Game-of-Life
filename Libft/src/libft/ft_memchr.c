/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:24:55 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
    The memchr() function scans the initial n bytes of the memory area pointed
	to by s for the first instance of c.  Both c and the bytes of the memory
	area pointed to by s are interpreted as unsigned char.

RETURN VALUE
	The memchr() and memrchr() functions return a pointer to the matching byte
	or NULL if the character does not occur in the given memory area.
*/

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	find;
	size_t			i;

	str = (unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == find)
			return (str);
		str++;
		i++;
	}
	return ((void *)0);
}
