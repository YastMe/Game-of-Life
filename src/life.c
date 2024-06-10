/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:40:14 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 00:44:44 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life.h"

int	check_neighbors(t_data *data, int x, int y)
{
	int		i;

	i = 0;
	if (x > 0 && data->map[y][x - 1])
		i++;
	if (x < data->size_x - 1 && data->map[y][x + 1])
		i++;
	if (y > 0 && data->map[y - 1][x])
		i++;
	if (y < data->size_y - 1 && data->map[y + 1][x])
		i++;
	if (x > 0 && y > 0 && data->map[y - 1][x - 1] && data->map[y - 1][x - 1])
		i++;
	if (x > 0 && y < data->size_y - 1 && data->map[y + 1][x - 1])
		i++;
	if (x < data->size_x - 1 && y < data->size_y - 1 && data->map[y + 1][x + 1])
		i++;
	if (x < data->size_x - 1 && y > 0 && data->map[y - 1][x + 1])
		i++;
	return (i);
}

static void	cell_lives(t_data *data, int x, int y)
{
	data->next_gen[x][y] = true;
	data->image_map[x][y]->enabled = true;
}

static void	cell_dies(t_data *data, int x, int y)
{
	data->next_gen[x][y] = false;
	data->image_map[x][y]->enabled = false;
}

static void	reassign(t_data *data)
{
	int	i;
	int	j;

	data->map = data->next_gen;
	data->next_gen = malloc(sizeof(bool *) * data->size_y);
	i = 0;
	while (i < data->size_y)
	{
		data->next_gen[i] = malloc(sizeof(bool) * data->size_x);
		j = 0;
		while (j < data->size_x)
		{
			data->next_gen[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
}

void	life(t_data *data)
{
	int	i;
	int	j;
	int	neighbors;

	reassign(data);
	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			neighbors = check_neighbors(data, j, i);
			if (data->map[i][j] && neighbors < 2)
				cell_dies(data, i, j);
			if (data->map[i][j] && (neighbors == 2 || neighbors == 3))
				cell_lives(data, i, j);
			if (data->map[i][j] && neighbors > 3)
				cell_dies(data, i, j);
			if (!data->map[i][j] && neighbors == 3)
				cell_lives(data, i, j);
			j++;
		}
		i++;
	}
	clean_array(data);
}
