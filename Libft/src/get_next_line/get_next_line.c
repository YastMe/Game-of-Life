/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:46:12 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/16 10:06:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_readstr(int fd, char *full_str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ((void *)0);
	bytes_read = 1;
	while (!ft_strchr_gnl(full_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(full_str);
			return ((void *)0);
		}
		buffer[bytes_read] = '\0';
		full_str = ft_strjoin_gnl(full_str, buffer);
	}
	free(buffer);
	return (full_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*full_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_str[fd] = ft_readstr(fd, full_str[fd]);
	if (!full_str[fd])
		return ((void *)0);
	line = ft_get_line_gnl(full_str[fd]);
	full_str[fd] = ft_get_remain_gnl(full_str[fd]);
	return (line);
}
