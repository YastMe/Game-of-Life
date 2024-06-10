/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:26:40 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:53 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Send the string 's' to the specified file descriptor.
*/

#include "../../include/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
