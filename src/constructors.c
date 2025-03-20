/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:34:43 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/20 15:53:34 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*alloc_map(t_info *table)
{
	t_map	*map;
	int		i;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->pts = ft_calloc(table->lines, sizeof(t_point *));
	if (!map->pts)
		return (free(map), NULL);
	i = -1;
	while (++i < table->lines)
	{
		map->pts[i] = ft_calloc(table->cols, sizeof(t_point));
		if (!map->pts[i])
			return (ft_free((void **) map, i), NULL);
	}
	map->cols = table->cols;
	map->lines = table->lines;
	map->scale = table->scale;
	map->z_scale = table->z_scale;
	map->size = table->cols * table->lines;
	fill_map(table->file_fd, map);
	return (map);
}

t_img	*get_img(t_fdf *fdf)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	if (!img->img)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	if (!img->addr)
		return (free(img), NULL);
	return (img);
}

// todo tratar os angulos e colormode?
t_fdf	*alloc_fdf(t_info *table)
{
	t_fdf	*fdf;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free(fdf), NULL);
	fdf->win_width = table->cols * SCALE;
	fdf->win_height = table->lines * SCALE;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width,
		 fdf->win_height, "fdf");
	if (!fdf->win)
		return (free(fdf), NULL);
	fdf->map = alloc_map(table);
	if (!fdf->map)
		return (free(fdf), NULL);
	return (fdf);
}
