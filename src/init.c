/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:51:49 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 01:08:29 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life.h"

static int	fill_images(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			data->image_map[i][j] = mlx_texture_to_image(data->mlx,
					data->textures->alive);
			if (!data->image_map[i][j])
				return (EXIT_FAILURE);
			if (mlx_image_to_window(data->mlx, data->image_map[i][j],
				j * 32, i * 32))
				return (EXIT_FAILURE);
			data->image_map[i][j]->enabled = false;
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_img_map(t_data *data)
{
	int	i;

	i = 0;
	data->image_map = malloc(sizeof(mlx_image_t *) * data->size_y);
	while (i < data->size_y)
	{
		data->image_map[i] = malloc(sizeof(mlx_image_t) * data->size_x);
		if (!data->image_map[i])
			return (EXIT_FAILURE);
		i++;
	}
	return (fill_images(data));
}

static void	load_textures(t_textures *textures)
{
	textures->alive = mlx_load_png("./textures/alive.png");
	textures->dead = mlx_load_png("./textures/dead.png");
}

static void	delete_textures(t_textures *textures)
{
	mlx_delete_texture(textures->alive);
	mlx_delete_texture(textures->dead);
}

int	init_data(t_data *data)
{
	t_textures	textures;

	map_size(data);
	data->map = malloc(sizeof(bool *) * data->size_y);
	if (!data->map)
		return (EXIT_FAILURE);
	load_textures(&textures);
	data->textures = &textures;
	if (init_map(data))
		return (EXIT_FAILURE);
	read_map_file(data);
	data->next_gen = data->map;
	data->mlx = mlx_init(data->size_x * 32, data->size_y * 32, "life", false);
	populate_map(data);
	init_img_map(data);
	delete_textures(data->textures);
	data->time_step = 0.3;
	data->deltatime = 0;
	return (EXIT_SUCCESS);
}
