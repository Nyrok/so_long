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
# include "./ft_printf.h"
# include "./libft.h"
# include "./get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"
# define EMPTY '0'
# define WALL '1'
# define EXIT 'E'
# define ITEM 'C'
# define SPAWN 'P'

typedef struct s_map
{
	char	*content;
	size_t	line_len;
	size_t	line_count;
}	t_map;

void	check_map(char *path, t_map *map);
void	map_error(char *message);
void	backtest(t_map *map);

#endif
