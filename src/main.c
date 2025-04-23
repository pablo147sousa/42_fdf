/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:03 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 15:14:41 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manager(t_data *data)
{
	mlx_hook(data->fdf->win, 17, 0, close_win_mouse, data);
	mlx_hook(data->fdf->win, 2, 1L << 0, key_press, data);
}

int	handle_line(t_fdf *fdf, t_point *start, t_point *end)
{
	t_point	new_start;
	t_point	new_end;

	if (!start || !end)
		return (1);
	new_start = *start;
	new_end = *end;
	new_start.abs = (new_start.abs + fdf->t.move_x) * fdf->t.scale;
	new_start.ord = (new_start.ord + fdf->t.move_y) * fdf->t.scale;
	new_start.value = new_start.value * fdf->t.scale;
	new_end.abs = (new_end.abs + fdf->t.move_x) * fdf->t.scale;
	new_end.ord = (new_end.ord + fdf->t.move_y) * fdf->t.scale;
	new_end.value = new_end.value * fdf->t.scale;
	rotation_x(&new_start, &new_end, fdf->t.angle_x);
	rotation_y(&new_start, &new_end, fdf->t.angle_y);
	rotation_z(&new_start, &new_end, fdf->t.angle_z);
	draw_line(fdf, &new_start, &new_end);
	return (0);
}

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
				handle_line(data->fdf, &data->fdf->map->pts[i][j],
					&data->fdf->map->pts[i][j + 1]);
			if (i != (data->table->lines - 1))
				handle_line(data->fdf, &data->fdf->map->pts[i][j],
					&data->fdf->map->pts[i + 1][j]);
		}
		mlx_put_image_to_window(data->fdf->mlx, data->fdf->win,
			data->fdf->img->img, 0, 0);
	}
	return (1);
}

int	render_map(t_data *data)
{
	static t_transform	transf;

	if (!ft_memcmp(&transf, &data->fdf->t, sizeof(t_transform)))
		return (0);
	transf = data->fdf->t;
	if (data->fdf && data->fdf->mlx && data->fdf->img)
	{
		mlx_destroy_image(data->fdf->mlx, data->fdf->img->img);
		free(data->fdf->img);
	}
	if (!draw_map(data))
		return (armageddon(data), 1);
	return (0);
}

int	main(int ac, const char **av)
{
	t_data	*data;

	if (ac != 2 || !valid_file(av[1]))
		return (ft_putstr_fd(ERR_FILENAME, 2), 1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (perror("data struct malloc"), 1);
	data->table = get_info(av[1]);
	if (!data->table)
		return (free(data), 0);
	data->fdf = alloc_fdf(data->table);
	if (!data->fdf)
		return (clean_table(data->table), free(data), 1);
	if (render_map(data) == 1)
		return (perror("erro img"), 1);
	print_menu();
	manager(data);
	mlx_loop_hook(data->fdf->mlx, render_map, data);
	mlx_loop(data->fdf->mlx);
	return (0);
}
