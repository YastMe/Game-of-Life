/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:59:14 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:18 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Using malloc(3), it generates a string that represents the integer value
	received as argument. Negative numbers have to be handled.

RETURN VALUE
	The string representing the number. NULL if the memory reservation fails.
*/

#include "../../include/libft.h"

static int	positive(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

static size_t	get_size(int num)
{
	size_t	size;

	size = 0;
	if (num <= 0)
		size++;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	size;

	size = get_size(n);
	ret = (char *)malloc((sizeof(char) * size) + 1);
	if (!ret)
		return ((void *)0);
	ret[size] = '\0';
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		size--;
		ret[size] = positive(n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
