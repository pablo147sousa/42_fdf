/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:48:24 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:27 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_high(t_map *map)
{
	int	i;
	int	j;
	int	high;

	i = -1;
	high = map->pts[0][0].value;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->pts[i][j].value > high)
				high = map->pts[i][j].value;
		}
	}
	return (high);
}

void	win_size(t_info *table, t_fdf *fdf)
{
	int	high;

	high = find_high(fdf->map);
	fdf->t.scale = MAX_WIN_SIZE / (ft_max(table->cols, table->lines));
	fdf->win_width = WIDTH;
	fdf->win_height = HEIGHT;
	fdf->t.scale = ft_min((fdf->win_width / table->cols),
			(fdf->win_height / table->lines));
	fdf->t.scale *= 0.5;
}

// void	win_size(t_info *table, t_fdf *fdf)
// {
// 	int	high;

// 	high = find_high(fdf->map);
// 	fdf->t.scale = MAX_WIN_SIZE / (ft_max(table->cols, table->lines));
// 	fdf->win_width = table->cols * fdf->t.scale;
// 	fdf->win_height = table->lines * fdf->t.scale;
// 	fdf->t.scale /= 2.5;
// }
