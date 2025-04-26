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
			exit_error("(Map) First/last line is not a wall.");
		i++;
	}
}

static void	check_line(char *line, char *last_line, size_t line_len)
{
	size_t	i;

	if (!line)
		check_wall(last_line);
	else if (ft_strlen(line) != line_len)
		exit_error("(Map) Line length mismatch.");
	else if (line[0] == '\n')
		exit_error("(Map) Empty lines.");
	else if (line[0] != WALL || line[line_len - 2] != WALL)
		exit_error("(Map) Line is not surrounded by walls.");
	else
	{
		i = 0;
		while (i < line_len - 1)
		{
			if (line[i] != WALL && line[i] != EMPTY && line[i] != EXIT \
				&& line[i] != ITEM && line[i] != SPAWN)
				exit_error("(Map) Invalid map chars.");
			i++;
		}
	}
}

void	check_map(char *path, t_map *map)
{
	int		fd;
	char	*last_line;
	char	*line;
	size_t	line_count;
	size_t	line_len;

	fd = safe_open(path);
	line = get_next_line(fd);
	map->content = ft_strjoin(map->content, line);
	line_count = 0;
	check_wall(line);
	line_len = ft_strlen(line);
	while (line != NULL)
	{
		line_count++;
		last_line = line;
		line = get_next_line(fd);
		check_line(line, last_line, line_len);
		if (line)
			map->content = ft_strjoin(map->content, line);
		free(last_line);
	}
	safe_close(fd);
	map->line_count = line_count;
	map->line_len = line_len;
}

void	check_content(t_map *map)
{
	if (!ft_strchr(map->content, ITEM))
	{
		free(map->content);
		exit_error("(Map) The map must have at least one item.");
	}
	if (ft_strcount(map->content, SPAWN) != 1)
	{
		free(map->content);
		exit_error("(Map) The map must have one player spawn.");
	}
	if (ft_strcount(map->content, EXIT) != 1)
	{
		free(map->content);
		exit_error("(Map) The map must have one exit.");
	}
}
