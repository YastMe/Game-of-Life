/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:27:47 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:35 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strlcpy() function copies up to size - 1 characters from the
	NUL-terminated string src to dst, NUL-terminating the result.

RETURN VALUE
	strlcpy() returns the total length of the string they tried to create.
	That means the length of src.
*/

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	char	*aux_src;

	aux_src = (char *)src;
	i = 0;
	if (size > 0)
	{
		while (aux_src[i] && i < size - 1)
		{
			dst[i] = aux_src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
			i++;
	return (i);
}
