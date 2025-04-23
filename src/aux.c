/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:54:37 by pmoreira          #+#    #+#             */
/*   Updated: 2025/04/23 14:41:45 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_value(const char *str, char **endptr, int base)
{
	long	color;

	color = ft_strtol(str, endptr, base);
	if (color < INT_MIN || color > INT_MAX)
		return (-1);
	return ((int) color);
}

static int	check_input(char *start, char *end)
{
	char	*ptr;

	if (!start || !end || start >= end)
		return (0);
	ptr = start;
	get_value(ptr, &ptr, 10);
	if (*ptr == ',')
	{
		ptr++;
		get_value(ptr, &ptr, 16);
	}
	if (ptr != end)
		return (0);
	return (1);
}

static int	is_valid(char *line, int size)
{
	char	*ptr;
	char	*start;
	char	*end;
	int		i;

	ptr = line;
	i = 0;
	while (i < size)
	{
		while (*ptr && ft_isspace(*ptr))
			ptr++;
		start = ptr;
		while (*ptr && !ft_isspace(*ptr))
			ptr++;
		end = ptr;
		if (!check_input(start, end))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_word(const char *s, char c)
{
	int	size;

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

int	validator(t_info *table)
{
	char	*line;
	int		count;
	int		i;

	line = get_next_line(table->file_fd);
	if (!line)
		return (close(table->file_fd), 0);
	count = ft_count_word(line, ' ');
	i = 1;
	while (1)
	{
		free(line);
		line = get_next_line(table->file_fd);
		if (!line)
			break ;
		i++;
		if (!is_valid(line, count) || (count != ft_count_word(line, ' ')))
			return (close(table->file_fd), free(line), 0);
	}
	free(line);
	close(table->file_fd);
	table->lines = i;
	table->cols = count;
	return (1);
}
