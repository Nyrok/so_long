/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:18:00 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/17 13:19:13 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "./ft_printf.h"
# include "./libft.h"
# include "./get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"
# define SIZE 64
# define EMPTY '0'
# define WALL '1'
# define EXIT 'E'
# define ITEM 'C'
# define SPAWN 'P'
# define VISITED 'X'
# define MAP_FILE_EXTENSION ".ber"
# define BACKGROUND_TEXTURE "./textures/background.xpm"
# define WALL_TEXTURE "./textures/wall.xpm"
# define EXIT_TEXTURE "./textures/exit.xpm"
# define ITEM_TEXTURE "./textures/item.xpm"
# define PLAYER_TEXTURE "./textures/player.xpm"

typedef struct s_map
{
	int		fd;
	char	*content;
	char	**lines;
	char	**copy_lines;
	void	*mlx;
	void	*mlx_wdw;
	void	**imgs;
	int		size_x;
	int		size_y;
	int		spawn_x;
	int		spawn_y;
	size_t	line_len;
	size_t	line_count;
	size_t	imgs_count;
}	t_map;

void	init_map(char *path, t_map *map);
void	exit_error(t_map *map, char *message);
void	backtrack(t_map *map);
int		safe_open(t_map *map, char *path);
void	safe_close(t_map *map, int fd);
void	free_map(t_map *map);
void	free_gnl(int fd, char *line, char *last_line);
int		ft_strcount(char *str, char c);
void	check_map(char *path, t_map *map);
void	check_content(t_map *map);
void	init_window(t_map *map);

#endif
