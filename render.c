/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:19:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/22 15:41:15 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_game *game, t_image *map, t_window *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window (mlx->mlx, mlx->win,
					map->road_img, j * 64, i * 64);
				mlx_put_image_to_window (mlx->mlx, mlx->win,
					map->wall_img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	render_player(t_game *game, t_image *map, t_window *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->road_img, j * 64, i * 64);
				render_direction(mlx, game, i, j);
			}
			j++;
		}
		i++;
	}
}

void	render_coin(t_game *game, t_image *map, t_window *mlx)
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
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->road_img, j * 64, i * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					coin, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	render_exit(t_game *game, t_image *map, t_window *mlx)
{
	int		i;
	int		j;
	void	*exit;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				exit = map->exit_img;
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					map->road_img, j * 64, i * 64);
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					exit, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	render_road(t_game *game, t_image *map, t_window *mlx)
{
	int		i;
	int		j;
	void	*road;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
			{
				road = map->road_img;
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					road, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
