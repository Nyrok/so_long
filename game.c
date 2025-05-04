/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
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
			if (map->lines[i][j] == c)
				mlx_put_image_to_window(map->mlx, map->mlx_wdw, \
					img, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	map->imgs[map->imgs_count++] = img;
}

static void	player_move(t_map *map, int x, int y)
{
	if (map->lines[map->player_y + y][map->player_x + x] == WALL)
		return ;
	else if (map->lines[map->player_y + y][map->player_x + x] == EXIT)
	{
		if (map->remaining_items)
			return ;
		else
			exit_game(map);
	}
	else if (map->lines[map->player_y + y][map->player_x + x] == ITEM)
		map->remaining_items--;
	map->lines[map->player_y][map->player_x] = EMPTY;
	map->lines[map->player_y + y][map->player_x + x] = PLAYER;
	map->player_y += y;
	map->player_x += x;
	ft_printf("Moves count: %i\n", ++map->moves_count);
}

static void	render_map(t_map *map)
{
	size_t	i;
	size_t	j;
	int		img_index;

	i = -1;
	while (++i < map->line_count)
	{
		j = 0;
		while (j < map->line_len)
		{
			if (map->lines[i][j] == EMPTY)
				img_index = 0;
			else if (map->lines[i][j] == WALL)
				img_index = 1;
			else if (map->lines[i][j] == ITEM)
				img_index = 2;
			else if (map->lines[i][j] == PLAYER)
				img_index = 3;
			else if (map->lines[i][j] == EXIT)
				img_index = 4;
			mlx_put_image_to_window(map->mlx, map->mlx_wdw, \
				map->imgs[img_index], j * SIZE, i * SIZE);
			j++;
		}
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 119)
		player_move(map, 0, -1);
	else if (keycode == 97)
		player_move(map, -1, 0);
	else if (keycode == 115)
		player_move(map, 0, 1);
	else if (keycode == 100)
		player_move(map, 1, 0);
	else if (keycode == 65307)
		exit_game(map);
	mlx_clear_window(map->mlx, map->mlx_wdw);
	render_map(map);
	return (0);
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
	map->imgs = malloc(5 * sizeof(void *));
	if (!map->imgs)
		exit_error(map, "Malloc failed for imgs");
	map->moves_count = 0;
	map->imgs_count = 0;
	game_insert(map, EMPTY, BACKGROUND_TEXTURE);
	game_insert(map, WALL, WALL_TEXTURE);
	game_insert(map, ITEM, ITEM_TEXTURE);
	game_insert(map, PLAYER, PLAYER_TEXTURE);
	game_insert(map, EXIT, EXIT_TEXTURE);
	mlx_hook(map->mlx_wdw, 3, 1L << 1, key_hook, map);
	mlx_hook(map->mlx_wdw, 17, 0, exit_game, map);
	mlx_loop(map->mlx);
}
