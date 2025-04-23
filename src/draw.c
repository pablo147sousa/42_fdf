/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:16 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 14:47:24 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_struct(t_bres *b, t_fdf *fdf, t_point *start, t_point *end)
{
	b->x0 = (start->abs + fdf->offset) * fdf->t.zoom;
	b->y0 = (start->ord + fdf->offset) * fdf->t.zoom;
	b->x1 = (end->abs + fdf->offset) * fdf->t.zoom;
	b->y1 = (end->ord + fdf->offset) * fdf->t.zoom;
	b->color = start->color;
	b->dx = ft_abs(b->x1 - b->x0);
	b->dy = -ft_abs(b->y1 - b->y0);
	if (b->x0 < b->x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (b->y0 < b->y1)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx + b->dy;
}

void	draw_line(t_fdf *fdf, t_point *start, t_point *end)
{
	t_bres	b;

	fill_struct(&b, fdf, start, end);
	while (1)
	{
		if (b.x0 >= 0 && b.x0 < fdf->win_width
			&& b.y0 >= 0 && b.y0 < fdf->win_height)
			put_pixel(fdf->img, b.x0, b.y0, b.color);
		if (b.x0 == b.x1 && b.y0 == b.y1)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 >= b.dy)
		{
			b.err += b.dy;
			b.x0 += b.sx;
		}
		if (b.e2 <= b.dx)
		{
			b.err += b.dx;
			b.y0 += b.sy;
		}
	}
}
