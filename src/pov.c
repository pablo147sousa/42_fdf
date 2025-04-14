/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:42:11 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/14 16:59:24 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *fdf)
{
	fdf->angle_x = 30;
	fdf->angle_y = 330;
	fdf->angle_z = 45;
}

void	top_v(t_fdf *fdf)
{
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
}

void	side_v(t_fdf *fdf)
{
	fdf->angle_x = 90;
	fdf->angle_y = 90;
	fdf->angle_z = 0;
}

void	front_v(t_fdf *fdf)
{
	fdf->angle_x = 90;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
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