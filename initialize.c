/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:40:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/13 12:40:07 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_wall(void *mlx, t_map *map)
{
	int	size;

	size = 64;
	map->wall_img = mlx_xpm_file_to_image(mlx, WALL, &size, &size);	
}

void	render_wall(t_game *game, t_map *map, t_window *mlx)
{
	int		i;
	int		j;
	void	*wall;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				wall = map->wall_img;
				mlx_put_image_to_window(mlx->mlx, mlx->win, wall, j * 64 , i * 64);
			}
			j++;
		}
		i++;
	}
}

void	initialize_player(void *mlx, t_map *map)
{
	int	size;

	size = 64;
	map->player_img = mlx_xpm_file_to_image(mlx, PLAYER, &size, &size);	
}

void	render_player(t_game *game, t_map *map, t_window *mlx)
{
	int		i;
	int		j;
	void	*player;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				player = map->player_img;
				mlx_put_image_to_window(mlx->mlx, mlx->win, player, j * 64 , i * 64);
			}
			j++;
		}
		i++;
	}
}

void	initialize_coin(void *mlx, t_map *map)
{
	int	size;

	size = 64;
	map->coin_img = mlx_xpm_file_to_image(mlx, COIN, &size, &size);	
}

void	render_coin(t_game *game, t_map *map, t_window *mlx)
{
	int		i;
	int		j;
	void	*coin;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				coin = map->coin_img;
				mlx_put_image_to_window(mlx->mlx, mlx->win, coin, j * 64 , i * 64);
			}
			j++;
		}
		i++;
	}
}
