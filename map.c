/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:16:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/22 13:04:36 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != WALL)
			map_error("(Map) First/last line is not a wall.");
		i++;
	}
}

static void	check_line(char *line, char *last_line, size_t line_len)
{
	size_t	i;

	if (!line)
		check_wall(last_line);
	else if (line[0] == '\n')
		map_error("(Map) Empty lines.");
	else if (line[0] != WALL || line[line_len - 2] != WALL)
		map_error("(Map) Line is not surrounded by walls.");
	else if (ft_strlen(line) != line_len)
		map_error("(Map) Line length mismatch.");
	else
	{
		i = 0;
		while (i < line_len - 1)
		{
			if (line[i] != WALL && line[i] != EMPTY && line[i] != EXIT \
				&& line[i] != ITEM && line[i] != SPAWN)
				map_error("(Map) Invalid map char.");
			i++;
		}
	}
}

int	check_map(char *path)
{
	int		fd;
	char	*last_line;
	char	*line;
	size_t	line_count;
	size_t	line_len;

	fd = open(path, O_RDONLY);
	line_count = 0;
	line = get_next_line(fd);
	check_wall(line);
	line_len = ft_strlen(line);
	while (line != NULL)
	{
		line_count++;
		last_line = line;
		line = get_next_line(fd);
		check_line(line, last_line, line_len);
	}
	return (1);
}
