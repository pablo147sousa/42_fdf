/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:56:22 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 15:33:14 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valid_file(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (!ft_strncmp(&filename[len - 4], ".fdf", 4));
}

int	testkey(int key_code, t_data *data)
{
	(void) data;
	ft_printf("key_code: %d\n", key_code);
	return (0);
}

void	print_menu(void)
{
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("~ /$$      /$$ /$$$$$$$$ /$$   /$$ /$$   /$$~\n");
	ft_printf("~| $$$    /$$$| $$_____/| $$$ | $$| $$  | $$~\n");
	ft_printf("~| $$$$  /$$$$| $$      | $$$$| $$| $$  | $$~\n");
	ft_printf("~| $$ $$/$$ $$| $$$$$   | $$ $$ $$| $$  | $$~\n");
	ft_printf("~| $$  $$$| $$| $$__/   | $$  $$$$| $$  | $$~\n");
	ft_printf("~| $$\\  $ | $$| $$      | $$\\  $$$| $$  | $$~\n");
	ft_printf("~| $$ \\/  | $$| $$$$$$$$| $$ \\  $$|  $$$$$$/~\n");
	ft_printf("~|__/     |__/|________/|__/  \\__/ \\______/ ~\n");
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("----Rotations----\nVK_UP, VK_DOWN, VK_LEFT, VK_RIGHT\n");
	ft_printf("----Translations----\nKEY_W, KEY_S, KEY_D, KEY_A\n");
	ft_printf("----Zoom----\nT - ZOOM_IN\nY - ZOOM_OUT\n");
	ft_printf("----PRESETS----\n1 - ISOMETRIC\n2 - TOP_VIEW\n\
3 - SIDE_VIEW\n4 - FRONT_VIEW\n");
	ft_printf("----CLOSE----\nPress ESC or windows close button.\n");
}
