/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/09 16:46:06 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_wall(void *mlx, t_map *map)
{
	int	size;

	size = 64;
	map->wall_img = mlx_xpm_file_to_image(mlx, WALL, &size, &size);	
}