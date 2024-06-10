/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:23:00 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The atoi() function converts the initial portion of the string pointed to 
	by nptr to int.  The behavior is the same as strtol(nptr, NULL, 10);
	except that atoi() does not detect errors.

RETURN VALUE
       The converted value or 0 on error.
*/

#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	ret;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (nptr[i] == '+' || neg == -1)
		i++;
	ret = 0;
	while (ft_isdigit(nptr[i]))
		ret = (ret * 10) + (nptr[i++] - '0');
	return (ret * neg);
}
