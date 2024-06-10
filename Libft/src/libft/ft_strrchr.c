/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:42 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/22 08:37:26 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strrchr() function returns a pointer to the last occurrence of the
	character c in the string s.

RETURN VALUE
	return a pointer to the matched character or NULL if the character is not
	found. The terminating null byte is considered part of the string, so that
	if c is specified as aq\0aq, these functions return a pointer to the
	terminator.
*/

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
