/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:53:47 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/20 16:15:06 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef SCALE
#  define SCALE 30
# endif

# ifndef Z_SCALE
#  define Z_SCALE 30
# endif

/// @brief Structure that has the point information.
/// @param ord Position on the ordinate axis (Y).
/// @param abs Position on the abscissa axis (X).
typedef struct s_point
{
	int	ord;
	int	abs;
	int	value;
	int	color;
}	t_point;


typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// white 16777215
typedef struct s_info
{
	int			file_fd;
	int			cols;
	int			lines;
	float		scale;
	float		z_scale;
}	t_info;

typedef struct s_map
{
	unsigned int	size;
	int				cols;
	int				lines;
	float			scale;
	float			z_scale;
	t_point			**pts;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		win_width;
	int		win_height;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		color_mode;
}	t_fdf;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_transform
{
	float	mat[4][4];
}	t_transform;

typedef unsigned char	t_uchar;

void	fill_map(int fd, t_map *map);
void	draw_map(t_fdf *fdf);

// *AUX

int		validator(t_info *table);
int		get_value(const char *str, char **endptr, int base);

// *CONSTRUCTORS

t_img	*get_img(t_fdf *fdf);
t_fdf	*alloc_fdf(t_info *table);

// *CLEANERS

void	clean_table(t_info *table);
void	clean_map(t_map *map);
void	armageddon(t_fdf *fdf, t_info *table);
void	ft_free(void **matrix, int size);

// *UTILS

t_info	*get_info(const char *input);
void	put_pixel(t_img *img, t_point *p);

#endif