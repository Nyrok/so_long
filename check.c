/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:16:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/26 18:01:04 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	check_chrs(t_map *map, char *line, char *last_line, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < line_len - 1)
	{
		if (line[i] != WALL && line[i] != EMPTY && line[i] != EXIT \
			&& line[i] != ITEM && line[i] != PLAYER)
		{
			free_gnl(map->fd, line, last_line);
			exit_error(map, "(Map) Invalid map chars.");
		}
		i++;
	}
}

static void	check_wall(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != WALL)
		{
			free_gnl(map->fd, str, NULL);
			exit_error(map, "(Map) First/last line is not a wall.");
		}
		i++;
	}
}

static void	check_line(t_map *map, char *line, char *last_line, size_t line_len)
{
	if (!line)
		check_wall(map, last_line);
	else if (line[0] == '\n')
	{
		free_gnl(map->fd, line, last_line);
		exit_error(map, "(Map) Empty lines.");
	}
	else if (ft_strlen(line) != line_len)
	{
		free_gnl(map->fd, line, last_line);
		exit_error(map, "(Map) Line length mismatch.");
	}
	else if (line[0] != WALL || line[line_len - 2] != WALL)
	{
		free_gnl(map->fd, line, last_line);
		exit_error(map, "(Map) Line is not surrounded by walls.");
	}
	else
		check_chrs(map, line, last_line, line_len);
}

void	check_map(char *path, t_map *map)
{
	int		fd;
	char	*last_line;
	char	*line;
	size_t	line_count;
	size_t	line_len;

	fd = safe_open(map, path);
	line = get_next_line(fd);
	map->fd = fd;
	map->content = ft_strjoin(map->content, line);
	line_count = 0;
	line_len = ft_strlen(line);
	check_wall(map, line);
	while (line != NULL)
	{
		line_count++;
		last_line = line;
		line = get_next_line(fd);
		check_line(map, line, last_line, line_len);
		map->content = ft_strjoin(map->content, line);
		free(last_line);
	}
	map->line_count = line_count;
	map->line_len = line_len;
}

void	check_content(t_map *map)
{
	if (!ft_strchr(map->content, ITEM))
		exit_error(map, "(Map) The map must have at least one item.");
	if (ft_strcount(map->content, PLAYER) != 1)
		exit_error(map, "(Map) The map must have one player spawn.");
	if (ft_strcount(map->content, EXIT) != 1)
		exit_error(map, "(Map) The map must have one exit.");
}
