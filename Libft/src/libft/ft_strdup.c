/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:26:59 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strdup() function returns a pointer to a new string which is a
	duplicate of the string s.  Memory for the new string is obtained with 
	malloc(3), and can be freed with free(3).

RETURN VALUE
	On success, the strdup() function returns a pointer to the duplicated
	string.  It returns NULL if insufficient memory was available, with errno
	set to indicate the error.
*/

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (0);
	ret = ft_memcpy(ret, s, size);
	return (ret);
}
