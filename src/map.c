/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:36:58 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/19 16:58:42 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_point(t_point *point, char *start, char *end)
{
	char	*ptr;

	if (!point || !start || !end || start >= end)
		return (0);
	point->color = WHITE;
	ptr = start;
	point->value = get_value(ptr, &ptr, 10);
	if (*ptr == ',')
	{
		ptr++;
		point->color = get_value(ptr, &ptr, 16);
	}
	if (ptr != end)
		return (0);
	return (1);
}

static void	fill_col(char *line, t_point *col, int count, t_map *map)
{
	char	*ptr;
	char	*start;
	char	*end;
	int		i;

	ptr = line;
	i = 0;
	while (i < map->cols)
	{
		while (*ptr && ft_isspace(*ptr))
			ptr++;
		start = ptr;
		while (*ptr && !ft_isspace(*ptr))
			ptr++;
		end = ptr;
		if (!init_point(&col[i], start, end))
			return (free(line));
		col[i].ord = count;
		col[i].abs = i;
		i++;
	}
	free(line);
}

void	fill_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	if (!map)
		return ;
	line = get_next_line(fd);
	if (!line)
		return ;
	i = -1;
	while (++i < map->lines)
	{
		fill_col(line, map->pts[i], i, map);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
}
