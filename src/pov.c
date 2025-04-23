/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:42:11 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 14:51:22 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_fdf *fdf)
{
	fdf->t.angle_x = 60;
	fdf->t.angle_y = 45;
	fdf->t.angle_z = -15;
	fdf->t.move_x = 0;
	fdf->t.move_y = 0;
	fdf->t.zoom = 1;
	get_offset(fdf);
}

static void	top_v(t_fdf *fdf)
{
	fdf->t.angle_x = 0;
	fdf->t.angle_y = 0;
	fdf->t.angle_z = 0;
	fdf->t.move_x = 0;
	fdf->t.move_y = 0;
	fdf->t.zoom = 1;
	get_offset(fdf);
}

static void	side_v(t_fdf *fdf)
{
	fdf->t.angle_x = 90;
	fdf->t.angle_y = 90;
	fdf->t.angle_z = 0;
	fdf->t.move_x = 0;
	fdf->t.move_y = 0;
	fdf->t.zoom = 1;
	get_offset(fdf);
}

static void	front_v(t_fdf *fdf)
{
	fdf->t.angle_x = 90;
	fdf->t.angle_y = 0;
	fdf->t.angle_z = 0;
	fdf->t.move_x = 0;
	fdf->t.move_y = 0;
	fdf->t.zoom = 1;
	get_offset(fdf);
}

void	projection(t_fdf *fdf, int proj)
{
	if (proj == ISOMETRIC)
		isometric(fdf);
	else if (proj == TOP_VIEW)
		top_v(fdf);
	else if (proj == SIDE_VIEW)
		side_v(fdf);
	else if (proj == FRONT_VIEW)
		front_v(fdf);
}
