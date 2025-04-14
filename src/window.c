/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:22 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/14 16:50:21 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_map(t_data *data)
{
	int		i;
	int		j;

	data->fdf->img = get_img(data->fdf);
	if (!data->fdf->img || !data->fdf->img->img)
		return (0);
	i = -1;
	while (++i < (data->table->lines))
	{
		j = -1;
		while (++j < (data->table->cols))
		{
			if (j != (data->table->cols - 1))
				draw_line(data->fdf, &data->fdf->map->pts[i][j], &data->fdf->map->pts[i][j + 1]);
			if (i != (data->table->lines - 1))
				draw_line(data->fdf, &data->fdf->map->pts[i][j], &data->fdf->map->pts[i + 1][j]);
		}
		mlx_put_image_to_window(data->fdf->mlx, data->fdf->win, data->fdf->img->img, (data->fdf->scale * data->table->cols) / 2, (data->fdf->scale * data->table->lines) / 2);
	}
	return (1);
}

void	render_map(t_data *data)
{
	ft_printf("antes: %d\n", data->fdf->map->pts[0][0]);
	projection(data->fdf, ISOMETRIC);
	rotation_x(data->fdf);
	rotation_y(data->fdf);
	rotation_z(data->fdf);
	ft_printf("depoiss: %d\n", data->fdf->map->pts[0][0]);
	if(!draw_map(data))
		armageddon(data);
}
