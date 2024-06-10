/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:27:25 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Reserves (with malloc(3)) and returns a new string, formed by the
	concatenation of 's1' and 's2'.

RETURN VALUE
	The new string. NULL if the memory reservation fails.
*/

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1 || !s2)
		return ((void *)0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!ret)
		return ((void *)0);
	i = -1;
	while (++i < (int)len1)
		ret[i] = s1[i];
	i = -1;
	while (++i < (int)len2)
		ret[len1 + i] = s2[i];
	ret[len1 + i] = '\0';
	return (ret);
}
