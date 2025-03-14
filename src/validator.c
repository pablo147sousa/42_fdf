/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:36:58 by pmoreira          #+#    #+#             */
/*   Updated: 2025/03/12 16:23:05 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// && (ft_isdigit(*s) || *s == '-' || *s == '+')

int ft_count_word(const char *s, char c)
{
	int		size;

	size = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && (*s == c || ft_isspace(*s)))
			s++;
		if (*s)
			size++;
		while (*s != c && *s)
			s++;
	}
	return (size);
}

int	validator(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	count = ft_count_word(line, ' ');
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (count != ft_count_word(line, ' '))
			return (close(fd), free(line), 0);
	}
	free(line);
	close(fd);
	return (1);
}
