/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:35:10 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/19 16:51:51 by pmoreira         ###   ########.fr       */
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

void	armageddon(t_fdf *fdf, t_info *table)
{
	if (table)
		clean_table(table);
	if (!fdf)
		return ;
	if (fdf->map)
		clean_map(fdf->map);
	if (fdf->win)
		free(fdf->win);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
}
