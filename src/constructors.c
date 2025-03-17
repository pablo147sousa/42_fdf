/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:34:43 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/17 16:28:42 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_point(char **ptr, t_map *map, int col, int line)
{
	t_point	*point;
	int		i;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	i = 0;
	while(**ptr && !ft_isspace(**ptr))
	{
		point->value = ft_strtol((const) *ptr, ptr, 10);
		if (**ptr == ',')
			point->color = ft_strtol((const) *ptr, ptr, 16);
		else
			point->color = WHITE;
		*ptr++;
	}
	point->ord = line;
	point->abs = col;
	return (point);
}



void	create_col(int size, char *s, t_map *map)
{
	
}

t_map	*create_map(int size, char *line)
{
	t_map	*map;
	char	*ptr;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ptr = line;
	while (*ptr)
	{
		
	}
}