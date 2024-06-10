/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:24 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:31 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	 The strcmp() function compares the two strings s1 and s2.  The locale is
	 not taken into account (for a locale-aware comparison, see strcoll(3)).
	 The comparison is done using unsigned characters.

RETURN VALUE
	The strcmp() function return an integer less than, equal to, or greater
	 than zero if s1 (or the first n bytes thereof) is found, respectively,
	 to be less than, to match, or be greater than s2.
*/

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
