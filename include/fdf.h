/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:53:47 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/13 11:20:18 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>

/// @brief Structure that has the point information.
/// @param ord Position on the ordinate axis.
/// @param abs Position on the abscissa axis.
typedef struct s_point
{
	int	ord;
	int	abs;
	int	value;
	int	color;
}	t_point;

// white 16777215

typedef struct s_map
{
	int	size;
	int	col;
	int	line;
}	t_map;

typedef unsigned char	t_uchar;

int	validator(int fd);
int	get_color(int num);

#endif