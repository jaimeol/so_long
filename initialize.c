/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/19 11:46:27 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_wall(void *mlx, t_image *map)
{
	int	size;

	size = 128;
	map->wall_img = mlx_xpm_file_to_image(mlx, WALL, &size, &size);	
}

void	initialize_player(void *mlx, t_image *map)
{
	int	size;

	size = 128;
	map->player_img = mlx_xpm_file_to_image(mlx, PLAYER, &size, &size);	
}

void	initialize_coin(void *mlx, t_image *map)
{
	int	size;

	size = 128;
	map->coin_img = mlx_xpm_file_to_image(mlx, COIN, &size, &size);	
}


void	initialize_exit(void *mlx, t_image *map)
{
	int	size;

	size = 128;
	map->exit_img = mlx_xpm_file_to_image(mlx, EXIT, &size, &size);	
}
