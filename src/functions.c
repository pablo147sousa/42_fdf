/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:48:24 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/11 14:26:49 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// returns absolute value of number
int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	win_size(t_info *table, t_fdf *fdf)
{

	fdf->scale = 10;
	fdf->win_width = table->cols * fdf->scale;
	fdf->win_height = table->lines * fdf->scale;
	if (fdf->win_width < MIN_WIN_SIZE || fdf->win_height < MIN_WIN_SIZE)
	{
		fdf->scale = ft_max(MIN_WIN_SIZE / table->cols, MIN_WIN_SIZE / table->lines);
		fdf->win_width = table->cols * fdf->scale;
		fdf->win_height = table->lines * fdf->scale;
	}
	if (fdf->win_width > MAX_WIN_SIZE || fdf->win_height > MAX_WIN_SIZE)
	{
		fdf->scale = ft_min(MAX_WIN_SIZE / table->cols, MAX_WIN_SIZE / table->lines);
		fdf->win_width = table->cols * fdf->scale;
		fdf->win_height = table->lines * fdf->scale;
	}
}
