/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:16:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/22 17:45:01 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	safe_open(t_map *map, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error(map, "Can't open the file.");
	return (fd);
}

void	safe_close(t_map *map, int fd)
{
	if (close(fd) == -1)
		exit_error(map, "Can't close the file.");
}

int	ft_strcount(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
