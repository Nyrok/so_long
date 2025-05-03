/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:21:58 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/26 18:21:59 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	game_insert(t_map *map, char c, char *texture)
{
	void		*img;
	int			img_width;
	int			img_height;
	size_t		i;
	size_t		j;

	img = mlx_xpm_file_to_image(map->mlx, texture, \
		&img_width, &img_height);
	if (!img)
		exit_error(map, "Can't turn xpm to image.");
	i = 0;
	while (i < map->line_count)
	{
		j = 0;
		while (j < map->line_len)
		{
			if (map->lines[i][j++] != c)
				continue ;
			mlx_put_image_to_window(map->mlx, map->mlx_wdw, \
				img, (j - 1) * SIZE, i * SIZE);
		}
		i++;
	}
	map->imgs[map->imgs_count++] = img;
}

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		exit_error(map, "Cannot initialize mlx.");
	map->mlx_wdw = mlx_new_window(map->mlx, \
		map->size_x, map->size_y, "not_so_long");
	if (!map->mlx_wdw)
		exit_error(map, "Cannot create window.");
	map->imgs = malloc(1 * sizeof(void *));
	if (!map->imgs)
		exit_error(map, "Malloc failed for imgs");
	map->imgs_count = 0;
	game_insert(map, EMPTY, BACKGROUND_TEXTURE);
	game_insert(map, WALL, WALL_TEXTURE);
	game_insert(map, ITEM, ITEM_TEXTURE);
	game_insert(map, SPAWN, PLAYER_TEXTURE);
	game_insert(map, EXIT, EXIT_TEXTURE);
}
