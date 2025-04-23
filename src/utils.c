/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:31 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 14:53:32 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*get_info(const char *input)
{
	t_info	*table;

	table = ft_calloc(1, sizeof(t_info));
	if (!table)
		return (perror("table struct malloc "), NULL);
	table->file_fd = open(input, O_RDONLY);
	if (table->file_fd < 0)
		return (clean_table(table), perror("FD error "), NULL);
	if (!validator(table))
		return (clean_table(table), ft_putstr_fd(ERR_SIZE_MAP, 2), NULL);
	table->file_fd = open(input, O_RDONLY);
	if (table->file_fd < 0)
		return (clean_table(table), perror("FD error"), NULL);
	return (table);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win_keycode(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		armageddon(data);
		exit (0);
	}
	return (0);
}

int	close_win_mouse(t_data *data)
{
	armageddon(data);
	exit (0);
}

void	get_offset(t_fdf *fdf)
{
	int	temp;

	temp = (int) sqrt(pow(fdf->win_width, 2) + pow(fdf->win_height, 2));
	fdf->offset = temp / 4;
}
