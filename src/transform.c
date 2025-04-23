/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:40:05 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 14:58:43 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	matxmul(float mat[3][3], t_point *point)
{
	float	x;
	float	y;
	float	z;

	x = point->abs;
	y = point->ord;
	z = point->value;
	point->abs = (int)(x * mat[0][0] + y * mat[0][1] + z * mat[0][2]);
	point->ord = (int)(x * mat[1][0] + y * mat[1][1] + z * mat[1][2]);
	point->value = (int)(x * mat[2][0] + y * mat[2][1] + z * mat[2][2]);
}

void	rotation_x(t_point *start, t_point *end, float angle_x)
{
	float	radian_x;
	float	rot_x[3][3];

	radian_x = angle_x * (PI / 180);
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(radian_x);
	rot_x[1][2] = -sin(radian_x);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(radian_x);
	rot_x[2][2] = cos(radian_x);
	matxmul(rot_x, start);
	matxmul(rot_x, end);
}

void	rotation_y(t_point *start, t_point *end, float angle_y)
{
	float	radian_y;
	float	rot_y[3][3];

	radian_y = angle_y * (PI / 180);
	rot_y[0][0] = cos(radian_y);
	rot_y[0][1] = 0;
	rot_y[0][2] = sin(radian_y);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = -sin(radian_y);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(radian_y);
	matxmul(rot_y, start);
	matxmul(rot_y, end);
}

void	rotation_z(t_point *start, t_point *end, float angle_z)
{
	float	radian_z;
	float	rot_z[3][3];

	radian_z = angle_z * (PI / 180);
	rot_z[0][0] = cos(radian_z);
	rot_z[0][1] = -sin(radian_z);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(radian_z);
	rot_z[1][1] = cos(radian_z);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	matxmul(rot_z, start);
	matxmul(rot_z, end);
}
