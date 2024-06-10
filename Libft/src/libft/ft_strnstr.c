/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:33 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strnstr() function locates the	first occurrence of the
	null-termi-nated string little in the	string big, where not more than
	len characters are searched.  Characters that appear after a `\0'
	character are not searched.

RETURN VALUE
	If	little is an empty string, big is returned; if little occurs nowhere
	in	big, NULL is returned; otherwise a pointer to the first	character of
	the first occurrence of little is returned.
*/

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == 0 || big == little)
		return ((char *)big);
	i = ft_strlen(little);
	while (*big && i <= len)
	{
		if (!(ft_strncmp((char *)big, (char *)little, ft_strlen(little))))
			return ((char *)big);
		big++;
		i++;
	}
	return ((void *)0);
}
