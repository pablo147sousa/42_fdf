/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:41:56 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/13 11:19:38 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_uchar	get_t(int trgb)
{
	return (((t_uchar *)&trgb)[3]);
}

static t_uchar	get_r(int trgb)
{
	return (((t_uchar *)&trgb)[2]);
}

static t_uchar	get_g(int trgb)
{
	return (((t_uchar *)&trgb)[1]);
}

static t_uchar	get_b(int trgb)
{
	return (((t_uchar *)&trgb)[0]);
}

int	get_color(int num)
{
	t_uchar	trgb[4];
	trgb[0] = get_b(num);
	trgb[1] = get_g(num);
	trgb[2] = get_r(num);
	trgb[3] = get_t(num);
	return (*(int *)trgb);
}
