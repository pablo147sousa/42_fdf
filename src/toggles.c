/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:28:17 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 15:59:06 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translation(t_fdf *fdf, int key_code)
{
	if (key_code == KEY_W)
		fdf->t.move_y -= 20;
	else if (key_code == KEY_S)
		fdf->t.move_y += 20;
	else if (key_code == KEY_A)
		fdf->t.move_x -= 20;
	else if (key_code == KEY_D)
		fdf->t.move_x += 20;
}

static void	rotate_map(t_fdf *fdf, int key_code)
{
	if (key_code == VK_UP)
		fdf->t.angle_x -= 5;
	else if (key_code == VK_LEFT)
		fdf->t.angle_y -= 5;
	else if (key_code == VK_DOWN)
		fdf->t.angle_x += 5;
	else if (key_code == VK_RIGHT)
		fdf->t.angle_y += 5;
}

static void	map_zoom(int key_code, t_data *data)
{
	if (key_code == KEY_T)
	{
		data->fdf->t.zoom *= 1.2;
		data->fdf->offset /= 1.2;
	}
	else if (key_code == KEY_Y)
	{
		data->fdf->t.zoom /= 1.2;
		data->fdf->offset *= 1.2;
	}
}

static void	change_proj(t_data *data, int keycode)
{
	if (keycode == KEY_1)
		projection(data->fdf, ISOMETRIC);
	else if (keycode == KEY_2)
		projection(data->fdf, TOP_VIEW);
	else if (keycode == KEY_3)
		projection(data->fdf, SIDE_VIEW);
	else if (keycode == KEY_4)
		projection(data->fdf, FRONT_VIEW);
}

int	key_press(int key_code, t_data *data)
{
	close_win_keycode(key_code, data);
	change_proj(data, key_code);
	translation(data->fdf, key_code);
	rotate_map(data->fdf, key_code);
	map_zoom(key_code, data);
	return (0);
}
