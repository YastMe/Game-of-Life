/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:01:40 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/22 18:53:18 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_ptrlen(__UINTPTR_TYPE__ ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_printptr(__UINTPTR_TYPE__ ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_putptrn(__UINTPTR_TYPE__ ptr)
{
	int	total_length;

	total_length = 0;
	total_length += write(1, "0x", 2);
	if (ptr == 0)
		total_length += write(1, "0", 1);
	else
	{
		ft_printptr(ptr);
		total_length += ft_ptrlen(ptr);
	}
	return (total_length);
}
