/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:09:41 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/26 15:09:44 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	free_gnl(int fd, char *line, char *last_line)
{
	char	*gnl;

	free(line);
	free(last_line);
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
}

static void	free_mlx(t_map *map)
{
	if (map->mlx)
		free(map->mlx);
	if (map->mlx_wdw)
		free(map->mlx_wdw);
	if (map->imgs)
		while (map->imgs_count)
			free(map->imgs[map->imgs_count--]);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (map == NULL)
		return ;
	if (map->content)
		free(map->content);
	if (map->lines)
	{
		i = 0;
		while (i < map->line_count)
		{
			if (map->lines[i])
				free(map->lines[i]);
			if (map->copy_lines && map->copy_lines[i])
				free(map->copy_lines[i]);
			i++;
		}
		free(map->lines);
		if (map->copy_lines)
			free(map->copy_lines);
	}
	free_mlx(map);
	free(map);
}
