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

void	init_map(char *path, t_map *map)
{
	if (!map)
		exit_error(map, "Malloc for map failed.");
	map->content = NULL;
	map->lines = NULL;
	map->copy_lines = NULL;
	check_map(path, map);
	safe_close(map, map->fd);
	check_content(map);
	map->lines = ft_split(map->content, '\n');
	if (!map->lines)
		exit_error(map, "Malloc for lines failed.");
	backtrack(map);
}
