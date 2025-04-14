/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:16 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/14 16:59:42 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matxmul(float mat[3][3], t_point *point)
{
	float x;
	float y;
	float z;

	x = point->abs;
	y = point->ord;
	z = point->value;
	point->abs = x * mat[0][0] + y * mat[0][1] + z * mat[0][2];
	point->ord = x * mat[1][0] + y * mat[1][1] + z * mat[1][2];
	point->value = x * mat[2][0] + y * mat[2][1] + z * mat[2][2];
}

void	rotation_x(t_fdf *fdf)
{
	float	radian_x;
	float	rot_x[3][3];
	int		y;
	int		x;

	radian_x = (fdf->angle_x * PI) / 180;
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(radian_x);
	rot_x[1][2] = -sin(radian_x);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(radian_x);
	rot_x[2][2] = cos(radian_x);
	y = -1;
	while (++y < fdf->map->lines)
	{
		x = -1;
		while (++x < fdf->map->cols)
			matxmul(rot_x, &fdf->map->pts[y][x]);
	}
}

void	rotation_y(t_fdf *fdf)
{
	float	radian_y;
	float	rot_y[3][3];
	int		y;
	int		x;

	radian_y = fdf->angle_y * (PI / 180);
	rot_y[0][0] = cos(radian_y);
	rot_y[0][1] = 0;
	rot_y[0][2] = -sin(radian_y);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = sin(radian_y);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(radian_y);
	y = -1;
	while (++y < fdf->map->lines)
	{
		x = -1;
		while (++x < fdf->map->cols)
			matxmul(rot_y, &fdf->map->pts[y][x]);
	}
}

void	rotation_z(t_fdf *fdf)
{
	float	radian_z;
	float	rot_z[3][3];
	int		y;
	int		x;

	radian_z = fdf->angle_z * (PI / 180);
	rot_z[0][0] = cos(radian_z);
	rot_z[0][1] = -sin(radian_z);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(radian_z);
	rot_z[1][1] = cos(radian_z);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	y = -1;
	while (++y < fdf->map->lines)
	{
		x = -1;
		while (++x < fdf->map->cols)
			matxmul(rot_z, &fdf->map->pts[y][x]);
	}
}

// void	isometric(t_point *point, int angle)
// {
// 	int	previous_x;
// 	int	previous_y;

// 	previous_x = point->abs;
// 	previous_y = point->ord;

// 	// Fórmula de projeção isométrica
// 	point->abs = (int) (previous_x - previous_y) * cos(angle * PI / 180);
// 	point->ord = (int) (previous_x + previous_y) * sin(angle * PI / 180) - point->value;
// }

void	fill_struct(t_bres *b, t_fdf *fdf, t_point *start, t_point *end)
{
	b->x0 = start->abs * fdf->scale;
	b->y0 = start->ord * fdf->scale;
	b->x1 = end->abs * fdf->scale;
	b->y1 = end->ord * fdf->scale;
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

// void draw_line(t_fdf *fdf, t_point *start, t_point *end)
// {
// 	int x0 = start->abs * fdf->scale;
// 	int y0 = start->ord * fdf->scale;
// 	int x1 = end->abs * fdf->scale;
// 	int y1 = end->ord * fdf->scale;
// 	int color = start->color;

// 	int dx = ft_abs(x1 - x0);
// 	int dy = -ft_abs(y1 - y0);
// 	int sx = (x0 < x1) ? 1 : -1;
// 	int sy = (y0 < y1) ? 1 : -1;
// 	int err = dx + dy;

// 	while (1)
// 	{
// 		if (x0 >= 0 && x0 < fdf->win_width && y0 >= 0 && y0 < fdf->win_height) {
// 			put_pixel(fdf->img, x0, y0, color);
// 		}

// 		if (x0 == x1 && y0 == y1) break;

// 		int e2 = 2 * err;
// 		if (e2 >= dy) { err += dy; x0 += sx; }
// 		if (e2 <= dx) { err += dx; y0 += sy; }
// 	}
// }

// void bresenham(int x0, int y0, int x1, int y1, t_img *img)
// {
//     int dx = ft_abs(x1 - x0);
//     int dy = ft_abs(y1 - y0);

//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;

//     int erro = dx - dy;

//     while (1)
// 	{
//         put_pixel(img, x0, y0, WHITE);

//         if (x0 == x1 && y0 == y1)
//             break;

//         int e2 = 2 * erro;

//         if (e2 > -dy) {
//             erro -= dy;
//             x0 += sx;
//         }

//         if (e2 < dx) {
//             erro += dx;
//             y0 += sy;
//         }
//     }
// }
