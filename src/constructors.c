/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:34:43 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/19 16:47:56 by pmoreira         ###   ########.fr       */
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
