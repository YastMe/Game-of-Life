/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:27:35 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:36 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strlcat() function appends the NUL-terminated string src to the end
	of dst. It will append at most size - strlen(dst) - 1 bytes,
	NUL-terminating the result.

RETURN VALUE
	strlcat() functions returns the total length of the string they tried to
	create. For strlcat() that means the initial length of dst plus the length
	of src.
*/

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	final_lenght;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dst))
		final_lenght = ft_strlen(src) + size;
	else
		final_lenght = ft_strlen(src) + ft_strlen(dst);
	while (dst[i] > 0)
		i++;
	while (i < size - 1 && src[j] > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (final_lenght);
}
