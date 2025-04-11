/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:03 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/11 16:05:23 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO remove later
int	key_hook(int keycode, t_fdf *vars)
{
	(void ) vars;
	ft_printf("Hello from key_hook %d!\n", keycode);
	return (0);
}

int	main(int ac, const char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (perror("data struct malloc"), 1);
	data->table = get_info(av[1]);
	if (!data->table)
		return (free(data), 0);
	data->fdf = alloc_fdf(data->table);
	if (!data->fdf)
		return (clean_table(data->table), free(data), 1);
	render_map(data);
	if(!data->fdf->img)
		return(perror("erro img"), 1);
	mlx_hook(data->fdf->win, 2, 1L<<0, close_win_keycode, data);
	mlx_hook(data->fdf->win, 17, 0, close_win_mouse, data);
	mlx_loop(data->fdf->mlx);
	return (0);
}


// #define ESC_KEY 65307

// typedef struct s_datat {
//     void    *mlx;
//     void    *win;
// }               t_datat;

// int key_hookt(int keycode, t_datat *data)
// {
//     if (keycode == ESC_KEY)
//     {
//         mlx_destroy_window(data->mlx, data->win);
//         // Opcional: se você tiver outras coisas para limpar, faça aqui
//         exit(0);
//     }
//     return (0);
// }

// int main(void)
// {
//     t_datat  data;

//     data.mlx = mlx_init();
//     if (!data.mlx)
//     {
//         ft_putstr_fd("Error: mlx_init failed\n", 2);
//         return (1);
//     }

//     data.win = mlx_new_window(data.mlx, 800, 600, "MiniLibX Test");
//     if (!data.win)
//     {
//         ft_putstr_fd("Error: mlx_new_window failed\n", 2);
//         free(data.mlx);
//         return (1);
//     }

//     mlx_key_hook(data.win, key_hookt, &data);
//     mlx_loop(data.mlx);

//     // Normalmente não chegamos aqui porque saímos com ESC
//     return (0);
// }