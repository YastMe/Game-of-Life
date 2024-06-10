/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:19:14 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/22 18:53:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_putnbrn(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstrn("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_putnbrn(n / 10);
		n = n % 10;
	}
	if (n < 10)
		len += ft_putchar(n + 48);
	return (len);
}
