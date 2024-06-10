/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:24:15 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 01:08:11 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_textures
{
	mlx_texture_t	*alive;
	mlx_texture_t	*dead;
}	t_textures;

typedef struct s_data
{
	mlx_t		*mlx;
	bool		**map;
	bool		**next_gen;
	int			size_x;
	int			size_y;
	char		*filename;
	t_textures	*textures;
	mlx_image_t	***image_map;
	double		deltatime;
	double		time_step;
}	t_data;

/**
 * @brief Initialize the cell map.
 * 
 * @param data The data structure
 * @return int 0 if success, 1 if failure
*/
int		init_map(t_data *data);

/**
 * @brief Initialize the data structure.
 * 
 * @param data The data structure
 * @return int 0 if success, 1 if failure
*/
int		init_data(t_data *data);

/**
 * @brief Check the neighbors of a cell.
 * 
 * @param data The data structure
 * @param x The x position of the cell
 * @param y The y position of the cell
 * @return int The number of neighbors
*/
int		check_neighbors(t_data *data, int x, int y);

/**
 * @brief Sets the map size on the data structure.
 * 
 * @param data 
 */
void	map_size(t_data *data);

int		init_map(t_data *data);

int		init_img_map(t_data *data);

int		populate_map(t_data *data);

void	read_map_file(t_data *data);

void	clean_array(t_data *data);

void	clean_image_array(t_data *data);

void	free_next_gen(t_data *data);

void	life(t_data *data);

void	print_map(t_data *data);

#endif
