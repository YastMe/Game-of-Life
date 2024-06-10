/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:59:53 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 00:45:01 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life.h"

void	map_size(t_data *data)
{
	int		size_y;
	int		fd;
	char	*row;

	fd = open(data->filename, O_RDONLY);
	row = get_next_line(fd);
	if (!row)
		return ;
	data->size_x = ft_strlen(row);
	size_y = 0;
	while (row)
	{
		size_y++;
		free(row);
		row = get_next_line(fd);
	}
	if (row)
		free(row);
	data->size_y = size_y;
}

int	populate_map(t_data *data)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			img = mlx_texture_to_image(data->mlx, data->textures->dead);
			if (!img)
				return (EXIT_FAILURE);
			if (mlx_image_to_window(data->mlx, img, j * 32, i * 32))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_y)
	{
		data->map[i] = malloc(sizeof(bool) * data->size_x);
		if (!data->map[i])
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			data->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	set_values(t_data *data, int i, int j, char *row)
{
	if (row[j] == '0')
		data->map[i][j] = false;
	else
		data->map[i][j] = true;
}

void	read_map_file(t_data *data)
{
	int		i;
	int		j;
	int		fd;
	char	*row;

	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		return ;
	row = get_next_line(fd);
	if (!row)
		return ;
	i = 0;
	while (row)
	{
		j = 0;
		while (j < data->size_x)
		{
			set_values(data, i, j, row);
			j++;
		}
		i++;
		free(row);
		row = get_next_line(fd);
	}
}
