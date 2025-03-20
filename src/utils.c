/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:31 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/20 13:46:15 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*get_info(const char *input)
{
	t_info	*table;

	table = ft_calloc(1, sizeof(t_info));
	if (!table)
		return (NULL);
	table->file_fd = open(input, O_RDONLY);
	if (table->file_fd < 0)
		return (clean_table(table), NULL);
	if (!validator(table))
		return (clean_table(table), NULL);
	table->file_fd = open(input, O_RDONLY);
	if (table->file_fd < 0)
		return (clean_table(table), NULL);
	table->scale = SCALE;
	table->z_scale = Z_SCALE;
	return (table);
}

void	put_pixel(t_img *img, t_point *p)
{
	char	*dst;

	dst = img->addr + (p->ord * img->line_length + p->abs * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = p->color;
}