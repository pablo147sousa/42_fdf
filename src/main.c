/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:03 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/19 16:36:55 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
int	main(int ac, const char **av)
{
	t_info	*table;
	t_map	*map;
	int i,j;

	if (ac != 2)
		return (1);
	table = get_info(av[1]);
	if (!table)
		return (0);
	// process_map(av[1], lines, cols, &map);
	ft_printf("mapa ok\n");
	ft_printf("lines:%d cols:%d\n", table->lines, table->cols);
	map = alloc_map(table);
	i = -1;
	while (++i < table->lines)
	{
		j = -1;
		while (++j < table->cols)
			ft_printf("[%d][%d] ", map->pts[i][j].ord, map->pts[i][j].abs);
		ft_printf("\n");
	}
	clean_map(map);
	armageddon(NULL, table);
	return (0);
}
// ft_printf("[%d][%d]:%d\n", i, j, map->pts[i][j].value);
// ft_printf("%d(%d) ", map->pts[i][j].value, map->pts[i][j].color);

