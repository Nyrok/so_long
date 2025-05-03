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

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_wdw = mlx_new_window(map->mlx, \
		map->size_x, map->size_y, "not_so_long");
}

void	init_textures(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_wdw = mlx_new_window(map->mlx, \
		map->size_x, map->size_y, "not_so_long");
}
