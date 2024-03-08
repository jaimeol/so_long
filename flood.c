/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:00 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/07 10:25:09 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(int x, int y, char **aux_map)
{
	if (aux_map[y][x] == 'E')
	{
		aux_map[y][x] = '1';
		return ;
	}
	aux_map[y][x] = '1';
	if (aux_map[y - 1][x] != '1')
		flood_map(x, y - 1, aux_map);
	if (aux_map[y + 1][x] != '1')
		flood_map(x, y + 1, aux_map);
	if (aux_map[y][x - 1] != '1')
		flood_map(x - 1, y, aux_map);
	if (aux_map[y][x + 1] != '1')
		flood_map(x + 1, y, aux_map);
}
