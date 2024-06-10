/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:55 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	strtrim removes all whitespace characters from the beginning and the end
	of a string. As whitespace is counted everything for which isspace(3)
	returns true.
*/

#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	char	*ret;

	if (!s1 || !set)
		return ((void *)0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s1 = ft_strlen(s1);
	while (len_s1 && ft_strchr(set, s1[len_s1]))
		len_s1--;
	ret = ft_substr((char *)s1, 0, len_s1 + 1);
	if (!ret)
		return ((void *)0);
	return (ret);
}
