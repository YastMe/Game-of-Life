/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:14 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:33 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	To each character in the string 's', apply the function 'f' giving as
	parameters the index of each character within 's' and the character itself.
	It generates a new string with the result of the successive use of 'f'.

RETURN VALUE
	The string created after the correct use of 'f' on each character. NULL if
	the memory reservation fails.
*/

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !f || !ret)
		return (NULL);
	index = 0;
	while (s[index])
	{
		ret[index] = f(index, (char)*(s + index));
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
