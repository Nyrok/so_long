/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <hkonte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:16:35 by hkonte            #+#    #+#             */
/*   Updated: 2025/04/22 13:43:05 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	exit_error(t_map *map, char *message)
{
	free_map(map);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
