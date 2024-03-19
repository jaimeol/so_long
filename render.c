/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:19:39 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/19 13:16:22 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game, t_window *window, t_image *image)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->y_large)
	{
		j = -1;
		while (++j < game->x_large)
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(window->mlx, window->win, image->player_img, j * 64, i * 64);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(window->mlx, window->win, image->wall_img, j * 64, i * 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(window->mlx, window->win, image->exit_img, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(window->mlx, window->win, image->coin_img, j * 64, i * 64);
		}
	}
	return (0);
}