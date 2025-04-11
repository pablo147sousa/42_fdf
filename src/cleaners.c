/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:35:10 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/09 13:14:28 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(void **matrix, int size)
{
	while (size > 0)
		free(matrix[--size]);
	free(matrix);
}

void	clean_table(t_info *table)
{
	if (!table)
		return ;
	if (table->file_fd > 0)
		close (table->file_fd);
	free(table);
}

void	clean_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->lines)
		free(map->pts[i]);
	free(map->pts);
	free(map);
}

void	armageddon(t_data *data)
{
	if (!data || !data->fdf || !data->table)
		return ;
	clean_table(data->table);
	if (data->fdf->map)
		clean_map(data->fdf->map);
	if (data->fdf->mlx)
	{
		if (data->fdf && data->fdf->mlx && data->fdf->img)
		{
			mlx_destroy_image(data->fdf->mlx, data->fdf->img->img);
			free(data->fdf->img);
		}
		if (data->fdf->win)
			mlx_destroy_window(data->fdf->mlx, data->fdf->win);
		if (data->fdf->mlx)
			mlx_destroy_display(data->fdf->mlx);
		free(data->fdf->mlx);
	}
	free(data->fdf);
	free(data);
}
