/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:22 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/19 13:28:43 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_map(t_info *table)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		return ;
	*map = create_map(fd, lines, cols);
}
