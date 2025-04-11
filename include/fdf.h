/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:53:47 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/11 16:04:54 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef SCALE
#  define SCALE 1.5
# endif

# ifndef Z_SCALE
#  define Z_SCALE 30
# endif

# ifndef ESC
#  define ESC 65307
# endif

# ifndef PI
#  define PI 3.14159265359
# endif

# ifndef MIN_WIN_SIZE
#  define MIN_WIN_SIZE 600
# endif

# ifndef MAX_WIN_SIZE
#  define MAX_WIN_SIZE 1000
# endif

// PROJECTIONS
# define ISOMETRIC 0
# define FRONT_VIEW 1
# define SIDE_VIEW 2
# define TOP_VIEW 3

/// @brief Structure that has the point information.
/// @param ord Position on the ordinate axis (Y).
/// @param abs Position on the abscissa axis (X).
typedef struct s_point
{
	int		ord;
	int		abs;
	int		value;
	int		color;
}	t_point;


typedef struct s_img
{
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
}	t_info;

typedef struct s_bres
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bres;

typedef struct s_map
{
	unsigned int	size;
	int				cols;
	int				lines;
	t_point			**pts;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
	int		win_width;
	int		win_height;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	scale;
	float	zoom;
	int		color_mode;
}	t_fdf;

typedef struct s_line
{
	t_point	*start;
	t_point	*end;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		p;
}	t_line;

typedef struct s_transform
{
	float	mat[4][4];
}	t_transform;

typedef struct s_data
{
	t_fdf	*fdf;
	t_info	*table;
}	t_data;


typedef unsigned char	t_uchar;

void	fill_map(int fd, t_map *map);
void	render_map(t_data *data);

// *AUX

int		validator(t_info *table);
int		get_value(const char *str, char **endptr, int base);

// *CONSTRUCTORS

t_img	*get_img(t_fdf *fdf);
t_fdf	*alloc_fdf(t_info *table);

// *CLEANERS , t_info *table

void	clean_table(t_info *table);
void	clean_map(t_map *map);
void	armageddon(t_data *data);
void	ft_free(void **matrix, int size);

// *UTILS

t_info	*get_info(const char *input);
void	put_pixel(t_img *data, int x, int y, int color);
int		close_win_keycode(int keycode, t_data *data);
int		close_win_mouse(t_data *data);
void	swap(int* a , int* b);

// *FUNCTIONS

int		roundNumber(float x);
int		iPartOfNumber(float x);
float	fPartOfNumber(float x);
float	rfPartOfNumber(float x);
int		ft_abs(int x);
void	win_size(t_info *table, t_fdf *fdf);

// *DRAW

void	draw_line(t_fdf *fdf, t_point *start, t_point *end);


void	projection(t_fdf *fdf, int proj);
void	rotation_z(t_fdf *fdf);
void	rotation_y(t_fdf *fdf);
void	rotation_x(t_fdf *fdf);

#endif