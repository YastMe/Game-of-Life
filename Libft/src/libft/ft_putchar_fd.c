/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:56 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:24:02 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Send the character 'c' to the specified file descriptor.
*/

#include "../../include/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
