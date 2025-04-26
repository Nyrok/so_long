/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:16:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/17 13:19:42 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	struct s_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	(void)argc;
	map->content = NULL;
	check_map(argv[1], map);
	map->lines = ft_split(map->content, '\n');
	backtrack(map);
	free(map->content);
	free(map);
}
