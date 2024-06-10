/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:43:56 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/22 18:53:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_putunsignedn(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putnbrn(n / 10);
		n = n % 10;
	}
	if (n < 10)
		len += ft_putchar(n + 48);
	return (len);
}
