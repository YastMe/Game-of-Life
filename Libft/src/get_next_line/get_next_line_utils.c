/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:46:49 by fragarci          #+#    #+#             */
/*   Updated: 2023/06/16 10:27:40 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen_gnl(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *full_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!full_str)
	{
		full_str = (char *)malloc(1 * sizeof(char));
		full_str[0] = '\0';
	}
	if (!full_str || !buff)
		return ((void *)0);
	str = malloc(sizeof(char) * ((ft_strlen_gnl(full_str)
					+ ft_strlen_gnl(buff)) + 1));
	if (str == (void *)0)
		return ((void *)0);
	i = -1;
	j = 0;
	if (full_str)
		while (full_str[++i] != '\0')
			str[i] = full_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(full_str) + ft_strlen_gnl(buff)] = '\0';
	free(full_str);
	return (str);
}

/* char	*ft_get_line_gnl(char *full_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!full_str[i])
		return ((void *)0);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return ((void *)0);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		str[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		str[i] = full_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
} */

char	*ft_get_line_gnl(char *full_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!full_str[i])
		return ((void *)0);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return ((void *)0);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		str[i] = full_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_remain_gnl(char *full_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
	{
		free(full_str);
		return ((void *)0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(full_str) - i + 1));
	if (!str)
		return ((void *)0);
	i++;
	j = 0;
	while (full_str[i])
		str[j++] = full_str[i++];
	str[j] = '\0';
	free(full_str);
	return (str);
}
