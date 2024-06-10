/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:26:47 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the
	character c in the string s.

RETURN VALUE
	The strchr() and strrchr() functions return a pointer to the matched
	character or NULL if the character is not found.  The terminating null
	byte is considered part of the string, so that if c is specified as '\0',
	these functions return a pointer to the terminator.
*/

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
