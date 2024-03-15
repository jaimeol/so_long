/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:32:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/03/15 12:17:18 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, int dir)
{
	game->map[game->y_p][game->x_p] = '0';
	if (dir == 0)
		game->y_p += 1;
	if (dir == 1)
		game->y_p -= 1;
	if (dir == 2)
		game->x_p -= 1;
	if (dir == 3)
		game->x_p += 1;
	game->map[game->y_p][game->x_p] = 'P';
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		movement(game, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		movement(game, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		movement(game, 2);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		movement(game, 3);
	/*if (keycode == KEY_ESCAPE)
		exit_game(game);*/
	return (0);
}
