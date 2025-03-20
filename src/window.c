/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:22 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/20 16:11:56 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;
	t_img	*img;

	img = get_img(fdf);
	if (!img)
		return ;
	i = -1;
	while (++i < (fdf->win_height / SCALE))
	{
		j = -1;
		while (++j < (fdf->win_width / SCALE))
		{
			put_pixel(img, &fdf->map->pts[i][j]);
// my_mlx_pixel_put(img, i, j, fdf->map->pts[i][j].color);
		}
		mlx_put_image_to_window(fdf->mlx, fdf->win, img->img, 0, 0);
	}
}
