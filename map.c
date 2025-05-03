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

static void	check_map_name(char *path, t_map *map)
{
	size_t	file_extension_len;
	size_t	path_len;
	size_t	offset;

	file_extension_len = ft_strlen(MAP_FILE_EXTENSION);
	path_len = ft_strlen(path);
	offset = path_len - file_extension_len;
	if (ft_strncmp(path + offset, MAP_FILE_EXTENSION, file_extension_len))
		exit_error(map, "Map file doesn't terminate by .ber");
}

void	init_map(char *path, t_map *map)
{
	if (!map)
		exit_error(map, "Malloc for map failed.");
	check_map_name(path, map);
	map->content = NULL;
	map->lines = NULL;
	map->copy_lines = NULL;
	map->mlx = NULL;
	map->mlx_wdw = NULL;
	check_map(path, map);
	safe_close(map, map->fd);
	check_content(map);
	map->lines = ft_split(map->content, '\n');
	if (!map->lines)
		exit_error(map, "Malloc for lines failed.");
	backtrack(map);
	map->size_x = map->line_len * 32;
	map->size_y = map->line_count * 32;
}
