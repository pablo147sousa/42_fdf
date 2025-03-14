/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:03 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/14 14:03:29 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, const char **av)
{
	int	fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (!validator(fd))
		return (ft_printf("mapa errado"), 0);
	ft_printf("mapa ok\n");
	ft_printf("cor:%d\n", strtol("111111111", NULL, 2));
	ft_printf("cor2:%d\n", ft_strtol("111111111", NULL, 2));
	ft_printf("test:%d\n", 0xFF0000);
	return (0);
}

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;

//     // Inicializa a conexão com o MiniLibX
//     mlx = mlx_init();
//     if (!mlx)
//         return (1);

//     // Cria uma janela de 800x600 pixels com o título "Draw Square"
//     mlx_win = mlx_new_window(mlx, 800, 600, "Draw Square");
//     if (!mlx_win)
//     {
//         mlx_destroy_display(mlx);
//         free(mlx);
//         return (1);
//     }

//     // Define a cor do quadrado (vermelho)
// 	// 16711680
//     char *color = "0xFF10A0"; //0x
//     // Desenha um quadrado de 50x50 pixels
//     int start_x = 375; // Posição inicial X
//     int start_y = 275; // Posição inicial Y
//     int size = 50;     // Tamanho do quadrado

//     for (int y = start_y; y < start_y + size; y++)
//     {
//         for (int x = start_x; x < start_x + size; x++)
//         {
//             mlx_pixel_put(mlx, mlx_win, x, y, ft_strtol(color, NULL, 16));
//         }
//     }

//     // Mantém a janela aberta e aguarda eventos
//     mlx_loop(mlx);

//     // Limpeza (nunca será alcançado neste exemplo simples)
//     mlx_destroy_window(mlx, mlx_win);
//     mlx_destroy_display(mlx);
//     free(mlx);

//     return (0);
// }
