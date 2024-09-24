/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:15:24 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/22 15:42:51 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_direction(t_window *mlx, t_game *game, int i, int j)
{
	if (game->player_dir == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			game->image.walkb_img, j * 64, i * 64);
	else if (game->player_dir == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			game->image.walkr_img, j * 64, i * 64);
	else if (game->player_dir == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			game->image.walkl_img, j * 64, i * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			game->image.player_img, j * 64, i * 64);
}
