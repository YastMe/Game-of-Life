/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:26:29 by abeltran          #+#    #+#             */
/*   Updated: 2024/06/11 00:36:33 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life.h"

void	clean_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_y)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	clean_image_array(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_y)
	{
		free(data->image_map[i]);
		i++;
	}
	free(data->image_map);
}

void	free_next_gen(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_y)
	{
		free(data->next_gen[i]);
		i++;
	}
	free(data->next_gen);
}
