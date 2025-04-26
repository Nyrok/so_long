/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:27:52 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/22 14:27:54 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	make_copy(t_map *map)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = ft_calloc(map->line_count + 1, sizeof(char *));
	if (!copy)
		exit_error("Malloc failed in backtrack");
	while (i < map->line_count)
	{
		copy[i] = ft_strdup(map->lines[i]);
		i++;
	}
	map->copy = copy;
}

static void	fill(t_map *map, int x, int y)
{
	int	line_count;
	int	line_len;

	line_count = (int)map->line_count;
	line_len = (int)map->line_len;
	if (x < 0 || y < 0 || y >= line_count || x >= line_len)
		return ;
	if (map->copy[y][x] == WALL || map->copy[y][x] == VISITED)
		return ;
	map->copy[y][x] = VISITED;
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

static int	find_spawn(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->line_count)
	{
		x = 0;
		while (x < map->line_len)
		{
			if (map->copy[y][x] == SPAWN)
			{
				map->spawn_x = (int)x;
				map->spawn_y = (int)y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_all_reachable(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->line_count)
	{
		x = 0;
		while (x < map->line_len)
		{
			if (map->copy[y][x] == ITEM || map->copy[y][x] == EXIT)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	backtrack(t_map *map)
{
	size_t	i;

	make_copy(map);
	if (!find_spawn(map))
		exit_error("Spawn point not found");
	fill(map, map->spawn_x, map->spawn_y);
	if (!check_all_reachable(map))
		exit_error("Map not reachable");
	i = 0;
	while (i < map->line_count)
		free(map->copy[i++]);
	free(map->copy);
}
