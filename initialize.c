/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/20 16:01:30 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_wall(void *mlx, t_image *map)
{
	int	size;

	size = 64;
	map->wall_img = mlx_xpm_file_to_image(mlx, WALL, &size, &size);	
}

void	initialize_player(void *mlx, t_image *map)
{
	int	size;

	size = 64;
	map->player_img = mlx_xpm_file_to_image(mlx, PLAYER, &size, &size);
	map->walkr_img = mlx_xpm_file_to_image(mlx, WALK_R, &size, &size);
	map->walkl_img = mlx_xpm_file_to_image(mlx, WALK_L, &size, &size);
	map->walkb_img = mlx_xpm_file_to_image(mlx, WALK_B, &size, &size);
}

void	initialize_coin(void *mlx, t_image *map)
{
	int	size;

	size = 64;
	map->coin_img = mlx_xpm_file_to_image(mlx, COIN, &size, &size);	
}


void	initialize_exit(void *mlx, t_image *map)
{
	int	size;

	size = 64;
	map->exit_img = mlx_xpm_file_to_image(mlx, EXIT, &size, &size);	
}

void	initialize_road(void *mlx, t_image *map)
{
	int	size;
	size = 64;
	map->road_img = mlx_xpm_file_to_image(mlx, ROAD, &size, &size);
}
