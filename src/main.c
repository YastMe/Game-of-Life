/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:25:17 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 01:13:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life.h"

static bool	check_file(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 6)
		return (false);
	if (filename[i - 5] == '.' && filename[i - 4] == 'l'
		&& filename[i - 3] == 'i' && filename[i - 2] == 'f'
		&& filename[i - 1] == 'e')
		return (true);
	return (false);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			ft_printf("%d", data->next_gen[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *) param;
	data->deltatime += data->mlx->delta_time;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		&& data->time_step > 0.1)
		data->time_step -= 0.1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		&& data->time_step < 1.0)
		data->time_step += 0.1;
	if (data->deltatime >= data->time_step)
	{
		data->deltatime = 0;
		life(data);
	}
}

void	ft_void(void)
{
	system("leaks -q life");
}

int	main(int argc, char **argv)
{
	t_data	data;

	atexit(ft_void);
	if (argc != 2)
	{
		printf("Usage: %s <filename.life>\n", argv[0]);
		return (1);
	}
	if (!check_file(argv[1]) && open(argv[1], O_RDONLY) < 0)
	{
		printf("Invalid file\n");
		return (1);
	}
	data.filename = argv[1];
	if (init_data(&data))
		return (0);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	clean_image_array(&data);
	free_next_gen(&data);
}
